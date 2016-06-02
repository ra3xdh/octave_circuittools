function sch_to_netlist(sch_file,net_file,net_type)
% Convert Qucs schematic *.sch to Qucs netlist
% sch_file is Qucs schematic filename 
% qucsnet_file is Netlist file name 
% net_type is type of netlist: "qucs" is Qucs
%                              "ngspice" is Ngspice
%			       "xyce" is Xyce

if nargin!=3
	print_usage;
	return
endif

switch net_type
case "qucs"
	netopt = "";
case "ngspice"
	netopt = " --ngspice ";
case "xyce"
	netopt = " --xyce ";
otherwise
	error("Unknown netlist type!");
       return;	
endswitch

if isempty(sch_file)
	error("Input filename is empty!\n");
	return;
endif

if isempty(net_file)
	error("Output filename is empty!\n");
	return;
endif

args = cstrcat(" -n ",netopt," -i \"",sch_file,"\" -o \"",net_file,"\"");
qucsdir = getenv("QUCSDIR");
if (!isempty(qucsdir))
	prog = strcat(qucsdir,"/bin/qucs"); 
else
	prog = "qucs";
endif
cmd = strcat(prog,args);
disp(cmd);
[status,output] = system(cmd);
if (status!=0) 
        fprintf(1,"There were Qucs execution errors!\n");
endif

endfunction

