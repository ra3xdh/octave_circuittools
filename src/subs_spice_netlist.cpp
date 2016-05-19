#include <octave/oct.h>



DEFUN_DLD (subs_spice_netlist, args, nargout,
	"-- Substitute parameter to SPICE netlsit subs_spice_netlist(FILE, PARAM, VALUE)")
{
    octave_value_list retval;

    int nargin =args.length();
    if (nargin!=3) {
	print_usage();
    } else {

	if (!error_state) {
	    retval(0) = octave_value(true);
	} else {
	    retval(0) = octave_value(false);
	}
    }
    return retval;
}



