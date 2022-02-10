# HPC

ese-msc-2021.github.io/ppp-make/slides/hpc.html

j.percival@imperial.ac.uk



## sshing to CX1 (College cluster)

- Connect to college network (Imperial-WPA on site, or use the VPN)

```
ssh jrper@login.hpc.ic.ac.uk
```

replace `jrper` with _your_ username


### Key glossary

- node: A "computer" in the cluster
- cpu: A processor core inside a computer
- task: A process on a node
- job: script/command submitted to the schedule


### Useful Modules

Add with `module add X`, remove with `module rm X` (or `module load/unload`)  

- `intel-suite/2019.4`: Add in the intel compilers (eg. `icpc` for C++)
- `gcc`: Add in a specific version of gcc
- `intel-mpi`: Intel implementation of  mpi
- `anaconda`: Add in python3 support via anaconda.


### Defining your job

```
#PBS -N mpi_test
#PBS -l walltime=1:00:00
#PBS -l select=2:ncpus=32:mpiprocs=32:mem=1GB

module load intel-suite
module load mpi

mpiexec ~/MPI_Example/my_code
```

First line
```
#PBS -N mpi_test
```
just sets a name. Used in (e.g.) `qstat` to identify your job, and controls the first part of the output `.o` (for stdout/cout) and `.e` (for stderr/cerr for _you_ and for the system)


``
#PBS -l walltime=1:00:00
``

Set the maximum run time before your job gets killed. Shorter jobs get queued faster, especially if you get short enough to be (e.g.) debug job class

```
#PBS -l select=2:ncpus=32:mpiprocs=32:mem=1GB
```

Big line, sets what resources you are asking for. In this case:
- 2 computers (nodes)
- with total of 32 cores
- Of which all 32 will do MPI (optional)
- Using 1GB memory on each computer (node)


### What job size should I use

- ICT publish general guidance on what's available
- Sometimes gets out of date.
- Try to stay as small as you can, but as large as you need
