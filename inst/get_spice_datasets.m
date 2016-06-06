function datasets = get_spice_datasets(netfile)
% Get SPICE datasets names from netlsit file (netfile)
%

if nargin!=1
   print_usage;
   return
endif

if isempty(netfile)
   error("Netlist filename is emplty!\n");
   return
endif


fid = fopen(netfile);

if fid == -1
   error("Cannot open netlist!\n");
   return
endif

n = 1;
while (!feof(fid))
   lin = fgetl(fid);
   lin = strtrim(lin);
   if regexp(lin,"^write\\s")
       S = strsplit(lin);
       datasets(n) = S(2);
       n++;
   endif
endwhile

fclose(fid);


endfunction
