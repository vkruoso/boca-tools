Easily create and manage BOCA contests with boca-tools
======================================================

This is a set of tools to easily create and manage BOCA contests. BOCA is a web-based programming contest system. The problem we are solving here is the tedious proccess of creating problems zip files and uploading them to the server. This can be a very tedious and time consuming task, even with the build problem interface in the BOCA system.

We provide a way of automate this task, as well as a few others on the way.

**NOTE: This script is compatible only with BOCA v1.5.1.**

First step
----------

Download the package using github and copy your boca configuration file (usually located at `boca/src/private/conf.php`) to the `boca/private/` folder. Make sure you can access your BOCA database server from the machine running boca-tools.

How to create new problems?
---------------------------

The problems folders contais a folder for each problem. The name of the folder is considered to be the problem's basename. Inside each problem folder, the script expect to find a configuration file named the same as the problem basename, but with the `.conf` extension.

So if you have a problem with basename `windows`, you should create the `windows/windows.conf` file. The problem's configuration file must have the following information:

    [info]
    fullname = Windows
    timelimit = 1

The fullname and timelimit are the only necessary information for a problem.
There are other files that a problem must have. They are:

    {basename}.in
    {basename}.out
    {basename}.tex
    
The in and out files are the problem input and output data, respectively. The tex file must be a latex file with the problem statement.


How to create new contests?
---------------------------

After you have all your problems in the system, you can create a new contests by creating a new folder inside the contests folder. Inside that folder create a `.conf` file with the same name. So if you create the `sample-contest` you will end up with this structure:

    /contests
      /sample-contest
        - sample-contest.conf
        
The configuration file must specify the contest informations. They include basic information to be printed in the contest first page, information about the problems, it's colors and possible timelimit modifications. Refer to the `contests/sample-contest/sample-contest.conf` file to check all available options.

After creating the configuration file, execute `./contests/create-contest sample-contest` to create the contest files.

The script will ask for you what you want to do, in this order:
  - Create latex files (will create all necessary latex files to create a nice looking PDF of the contest).
  - Generate problems zip files and upload them to the BOCA server.
  - Create some basic users (judges, staff and score).
