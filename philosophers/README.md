# Philosophers
In computer science, [The Dining Philosopher Problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem)  serves as a classic example often utilized in concurrent algorithm design to illustrate synchronization challenges and the techniques employed to address them.

What is Philosophers?
Philosophers is an individual project at Codam, tasking us with solving the Dining Philosopher Problem using threads, processes, mutex, and semaphores. The mandatory part necessitates solving it with threads and mutex. The implemented solution involves a monitoring thread that checks for any philosopher's demise, signaling others to cease their activities by locking the mutex. The bonus component involves using processes instead of threads and semaphores instead of mutex. To address this, the solution incorporates a death check between sleeping times, mitigating the issue of reporting a philosopher's death after more than 10 milliseconds.

Problem Statement
Proposed by Edsger W. Dijkstra in 1965, the problem is regarded as a classic in operating systems. It features five philosophers seated around a circular dinner table, each with a plate for spaghetti and a fork to their right. To eat, they require two forks, but only one fork is available between each pair of plates. A philosopher engages in three actions: eating, thinking, or sleeping. When a philosopher becomes hungry, they attempt to acquire the forks to their right and left one at a time. If successful, they proceed to eat, put the forks back on the table, go to sleep, and then resume thinking.


## Instructions
After running make, run the executable with the specified arguments in the given order (the last argument is optional):

number of philosophers, time to die, time to eat, time to sleep, numbers of times each must eat
