#include <octave/oct.h>

#define NETLIST_MAXLEN 512


DEFUN_DLD (subs_spice_netlist, args, nargout,
	"-- Substitute parameter to SPICE netlsit subs_spice_netlist(FILE, PARAM, VALUE)")
{
    octave_value_list retval;

    int nargin =args.length();
    if (nargin!=3) {
	print_usage();
    } else {

	std::string s_netlist = args(0).string_value();
	std::string s_param = args(1).string_value();
	double p_value = args(2).double_value();

	const char *netlist=s_netlist.c_str();
	char *tmpfile = (char *) malloc((strlen(netlist)+4)*sizeof(char));
	strcpy(tmpfile,netlist);
	strcat(tmpfile,".tmp");

	const char *param=s_param.c_str();
	FILE *src = fopen(netlist,"r");
	FILE *dst = fopen(tmpfile,"w");

	if ((!src)) {
	    retval(0) = octave_value(false);
	    return retval;
	}
	while (!feof(src)) {
	    size_t n = NETLIST_MAXLEN;
	    char *lin = (char *) malloc(NETLIST_MAXLEN*sizeof(char));
	    getline(&lin,&n,src);
	    char *start = lin;
	    while (isspace(*start)) start++;
	    if (*start=='*') continue; // Comment
	    if (!strncasecmp(start,".PARAM",6)) { // Parameter
		start += 6; // Start of param;
		while (isspace(*start)) start++;
		if (!strncasecmp(start,param,strlen(param))) {
		    start += strlen(param);
		    while ((isspace(*start))||(*start=='=')) start++;
		    sprintf(start,"%g\n",p_value);
		    printf("%s",lin); // Directive
		}
	    }
	    fputs(lin,dst);
	    free(lin);
	}
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



