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

% setenv("QUCSDIR","/mnt/Datei_3/qucs-s");

% Get Qucs netlist
sch_to_netlist("RC.sch",netfile,"qucs");

% Substitute resistor 2 kOhm
subs_qucs_netlist(netfile,"Rs",2e3);
% Substitute capacitor C = 2000pF
subs_qucs_netlist(netfile,"Cp",500e-12);

% Run Qucsator and obtain Qucs dataset
run_qucsator(netfile,"RC.dat");

DATA = loadQucsDataSet("RC.dat");

t = DATA(3).data; % time
inVt = DATA(6).data; % Input voltage
outVt = DATA(7).data; % Output voltage

plot(t,inVt,t,outVt);

pause;

