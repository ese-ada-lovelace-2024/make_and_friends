# HPC

ese-msc-2023.github.io/ppp-make/slides/hpc.html

j.percival@imperial.ac.uk



## Reminders: sshing to the College cluster

- Connect to college network (via Imperial-WPA on site, or use the VPN)

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

- `tools/prod`: Get the CX3 build tools (you want this first)
- `intel-compilers/2023.2.1`: Add in the intel compilers (eg. `icpc` for C++)
- `gcc`: Add in a specific version of gcc
- `impi`/`mpi-intel`: Intel implementation of  mpi
- `anaconda`: Add in python3 support via anaconda.


### Defining your job

```
#PBS -N mpi_test
#PBS -l walltime=1:00:00
#PBS -l select=1:ncpus=32:mpiprocs=32:mem=1GB

module load intel-suite
module load mpi

make
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

Set the maximum run time before your job gets killed. Shorter jobs get queued faster, especially if you get short enough to be in the (e.g.) debug job queue

```
#PBS -l select=2:ncpus=32:mpiprocs=32:mem=1GB
```

Big line, sets what resources you are asking for. In this case:
- 2 computers (nodes)
- with total of 32 cores each
- Of which all 32 will do MPI (optional for Non-MPI jobs)
- Using 1GB memory on each computer (node)


```
make
mpiexec ~/MPI_Example/my_code
```

- Actual payload of the job.
- Individual lines run in serial unless you use a parallel program (e.g. `mpiexec`, or `make -j 16`)
- No explicit `-n` flag for `mpiexec` so it will use all 32 cores on each node (as per the `#PBS -l` line).

## ncpus versus mpiprocs

- `ncpus` is the total number of cores you are asking for (including for MPI, OpenMP + anything else)
- `mpiprocs` is the number of cores you want to use for MPI tasks (if you are using MPI)

If you want 8 MPI tasks, and each task needs 4 cores (thanks to OpenMP), you would set `ncpus=32` and `mpiprocs=8` with `ompthreads=4` in your code.


### What job sizes should I use

- ICT publish general guidance on what's available in the cluster
- Sometimes gets out of date.
- Try to stay as small as you can, but as large as you need
- For short timing runs only, you may want a whole machine to yourself (e.g. `select=1:ncpus=32:mpiprocs=1:mem=1GB`)


## How to configure/build your code

- Best practice to work on the compute nodes (i.e. submit a job to the queue)
- On the ICT cluster, for small jobs it's sometimes possible (not recommended!) to work on the login node.
- Don't do it while 90 other people are trying to do the same thing.


### Building/Compiling

- Often easiest to submit a serial job.
- Load the modules you need first (e.g. intel compilers)
- Then compile your code based on the build system you are using:


```
#PBS -N mpi_test
#PBS -l walltime=0:10:00
#PBS -l select=1:ncpus=1:mem=1GB
module load tools/prod
module load intel-compilers
module load impi

mkdir -p build
cd build
cmake ..
make
```
