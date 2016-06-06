clear all;
clc;

% load all necessary packages
pkg load spiceraw;
pkg load circuittools;
% correct this line for actual path 
% to Qucs Octave packages
addpath('/usr/share/qucs/octave')

% make 
netfile = tempname();

setenv("QUCSDIR","/mnt/Datei_3/qucs-s");

% Get Qucs netlist
sch_to_netlist("RC.sch",netfile,"ngspice");

% Substitute resistor 2 kOhm
subs_spice_netlist(netfile,"Rs",2e3);
% Substitute capacitor C = 2000pF
subs_spice_netlist(netfile,"Cp",500e-12);

% Run Ngspice and obtain Qucs dataset
program = "ngspice"
cmd = cstrcat(program," ",netfile);
printf("Running Ngspice: %s\n",cmd);
system(cmd);

printf("SPICE datasets are:\n");
datasets = get_spice_datasets(netfile)

% Read transisent simulation data
DATA_TR = read_spiceraw(datasets(1));
t = DATA_TR(:,1);
inVt = DATA_TR(:,2);
outVt = DATA_TR(:,3);
subplot(2,1,1);
plot(t,inVt,t,outVt);

% Read AC simulation data
DATA_AC = read_spiceraw(datasets(2));
f = DATA_AC(:,1);
inV = DATA_AC(:,2);
outV = DATA_AC(:,3);
subplot(2,1,2);
plot(f,outV);


pause;

