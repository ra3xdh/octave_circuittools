### Description

`circuittools` is Octave package that allows to operate with SPICE netlists.
It provides a set of fucnctions for netlist parameter substitution.

### Installation

Use the following sequence to install Octave package:

* Download source code:
~~~
git clone https://github.com/ra3xdh/octave_ciruittools
cd octave_ciruittools
~~~ 
* Create Octave package
~~~
git archive --format=tar.gz --prefix=circuittools/ HEAD > ciruittools.tar.gz
~~~
* Start Octave
~~~
octave
~~~
* Install package into Octave. Execute into Octave console:
~~~
pkg install circuittools.tar.gz
~~~


