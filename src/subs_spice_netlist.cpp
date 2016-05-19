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

	const char *netlist=s_netlist.c_str();
	const char *param=s_param.c_str();
	FILE *fp = fopen(netlist,"r+");
	if (!fp) {
	    retval(0) = octave_value(false);
	    return retval;
	}
	while (!feof(fp)) {
	    size_t n = NETLIST_MAXLEN;
	    char *lin = (char *) malloc(NETLIST_MAXLEN*sizeof(char));
	    getline(&lin,&n,fp);
	    char *start = lin;
	    while (isspace(*start)) start++;
	    if (*start=='*') continue; // Comment
	    if (*start=='.') printf("%s",start); // Directive
	    free(lin);
	}
	fclose(fp);


	if (!error_state) {
	    retval(0) = octave_value(true);
	} else {
	    retval(0) = octave_value(false);
	}
    }
    return retval;
}



