**1. List all of the main states a process may be in at any point in time on a standard Unix system. Briefly explain what each of these states means.**

    1. Start or New - This is the initital state, when a process is first created or started.
	2. Ready - The process is is waiting for a processor to be assigned to them so that they can run.
	3. Running - Once the process gets a processor the state of the process is switched to running and the process executes.
	4. Waiting - The process moves into a waiting state if it needs to wait for something else to happen before it can terminate.
	5. Terminated - Once the process is finished with its execution, it is switched to a terminated state and it stis and waits to be removed from memory.


**2. What is a zombie process?**

    
	A zombie process is a process that has completed execution, it's in the
	terminated state, but has not been removed from the process table.


**3. How does a zombie process get created? How does one get destroyed?**

    A zombie process is created when a child process has executed but the process
	entry in the table is still needed by the parent process because it needs to
	know the child's exit status. However, once the parent has read the exit status
	the zombie process's entry in the process table is removed and the zombie is,
	"reaped", or destroyed.


**4. What are some of the benefits of working in a compiled language versus a non-compiled language? More specifically, what benefits are there to be had from taking the extra time to compile our code?**

	Since compiled languages end up translated by the compiler they end up binary, so they are written in the computer's language.
	This makes them faster and more efficient to execute.
