function run_qucsator(net_file,dataset)
% Run Qucsator on specified netlist net_file
% dataset is output dataset filename

if nargin!=2
	print_usage;
	return
endif

if isempty(net_file)
	error("Input netlist filename is empty!\n");
	return;
endif

if isempty(dataset)
	error("Output dataset filename is empty!\n");
	return;
endif

args = cstrcat(" -i \"",net_file,"\" -o \"",dataset,"\"");
qucsdir = getenv("QUCSDIR");
if (!isempty(qucsdir))
	prog = strcat(qucsdir,"/bin/qucsator"); 
else
	prog = "qucsator";
endif
cmd = strcat(prog,args);
disp(cmd);
[status,output] = system(cmd);
if (status!=0) 
        fprintf(1,"There were Qucsator execution errors!\n");
endif


endfunction
