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