#include <octave/oct.h>

#define NETLIST_MAXLEN 512


DEFUN_DLD (subs_spice_modelcard, args, nargout,
	"-- Substitute parameter to Qucs netlsit subs_spice_netlist(FILE, PARAM, VALUE)")
{
    octave_value_list retval;

    int nargin =args.length();
    if (nargin!=4) {
	print_usage();
    } else {

	std::string s_netlist = args(0).string_value();
	std::string s_model = args(1).string_value();
	std::string s_param = args(2).string_value();
	double p_value = args(3).double_value();

	const char *netlist=s_netlist.c_str();
	char *tmpfile = (char *) malloc((strlen(netlist)+4)*sizeof(char));
	strcpy(tmpfile,netlist);
	strcat(tmpfile,".tmp");

	const char *model = s_model.c_str();
	const char *param = s_param.c_str();
	FILE *src = fopen(netlist,"r");
	FILE *dst = fopen(tmpfile,"w");

	if ((!src)) {
	    retval(0) = octave_value(false);
	    return retval;
	}

	size_t n = NETLIST_MAXLEN;
	char *lin = (char *) malloc(NETLIST_MAXLEN*sizeof(char));
	bool continue_parsing = false;
	while (getline(&lin,&n,src)>0) {
	    char *start = lin;
	    int pos = 0;
	    if (*start!='+') continue_parsing = false; // Contunuation
	    else start++,pos++;

	    while (isspace(*start)) start++,pos++;
	    if (*start=='*') { // Comment
		fputs(lin,dst);
		continue;
	    }
	    if ((!strncasecmp(start,".MODEL",6))||continue_parsing) { // Modelcard found
		if (!continue_parsing) {
		    start += 6; // Start of modelcard;
		    pos += 6;
		    char name[32];
		    while (isspace(*start)) start++,pos++;
		    char *tmp=name;
		    while (!isspace(*start)) *tmp++ = *start++,pos++;
		    *tmp++ = '\0';
		    if (strcasecmp(name,model)) continue;
		    continue_parsing = true;
                    while (*start!='(') start++,pos++;
		    start++,pos++;
		}
		
		//while ((isalpha(*start))||(isdigit(*start))) start++,pos++;
		while (isspace(*start)) start++,pos++;
		while (*start) {
		    int p_len=0;
		    char *p_end = start;
		    while (isalpha(*p_end)||(isdigit(*p_end))) p_len++,p_end++,pos++;
		    char *n_par=(char *)malloc((p_len+1)*sizeof(char));
		    strncpy(n_par,start,p_len);
		    n_par[p_len]='\0';
		    int v_len = 0;
		    while (strchr(" \t=",*p_end)) p_end++,pos++;
		    //p_end++,pos++;
	            while (*p_end!=' ') p_end++,v_len++;
		    if (!strcasecmp(n_par,param)) {
			char *new_lin = (char *)malloc((strlen(lin)+32)*sizeof(char));
			strncpy(new_lin,lin,pos);
			new_lin[pos]='\0';
			char ss[16];
			sprintf(ss,"%g",p_value); // Substitute new value
			strcat(new_lin,ss);       // and combine all strings
			strcat(new_lin,p_end);
			strcpy(lin,new_lin);
			printf("%s\n",new_lin);
			free(new_lin);
			//free(lin);
			//lin = new_lin;
			break;
			continue_parsing = false;
		    }
		    pos += v_len;
		    start=p_end;
		    free(n_par);
		    start++,pos++;
		    while (isspace(*start)) start++,pos++;
		}
		//printf("%s\n",lin);
	    }
	    fputs(lin,dst);
	}
	free(lin);
	fclose(src);
	fclose(dst);

	rename(tmpfile,netlist);

	if (!error_state) {
	    retval(0) = octave_value(true);
	} else {
	    retval(0) = octave_value(false);
	}
    }
    return retval;
}



