## Problem set for Alberta Collegiate Programming Contest 2017

This problem set is using the Kattis Problem Format. For more information:

* <http://www.problemarchive.org/wiki/index.php/Introduction_to_the_Kattis_Problem_Format>
* <http://www.problemarchive.org/wiki/index.php/Problem_Format>

Since the judge will most likely be Kattis, strict compliance with the format is required. Every problem must have:

* problem.yaml
* Accepted solution
* Test data (do not duplicate sample data in the secret folder)
* Input format validator (**required**)

If possible, check your problem using Kattis [verifyproblem](https://github.com/Kattis/problemtools) tool. See the character problem (from CCPC 2017) for an example of a complete problem.

### Problems

Feel free to update this section with the types of problems or contact each other directly with comments.

* Wenli's -- character: Trivial Ad-hoc.
  * Modan: This is a sample problem from CCPC 2017.
* Kent's -- Checkpoints: DAG
  * Howard: I have no idea what is being asked for here, and I do not understand the sample output either.  It can probably be described more simply in English (instead of the "mapping").
* Kent's -- Matchings: FFT
  * Howard: There needs to be a specification of what order to output things in.  Also, I dislike the use of "x" and "y" coordinates because the coordinate system is not clear.  Use rows and columns instead?
  * Wenli: Note this is basically the exact same problem as "Best Position" from ICPC Kuala Lumpur Regional 2014.
* Modan's -- Divide by 100...: Easy string, implementation
  * Modan: I changed the problem from "Divide by 999..." so it's even easier.
  * Howard: "speicial" typo, should also specify leading 0's in front of decimal (0.xxx).
    * Modan: Fixed!
* Modan's -- Racetrack: Geometry
  * Modan: I'm too noob to write Delaunay triangulation to generate random simple polygons, so I changed the problem statement.
  * ~~Modan: Slight variation on computing polygon area, it is easier than it seems, however most teams might not know how to compute polygon area.~~
* Modan's -- Concentration: Ad-hoc, simulation, implementation
  * Modan: Pretty much simulating a game of concentration, implementation might not be trivial for most teams.
  * Howard: "More specially" -> "More specifically"?  It's not hard but I think it can be tricky.
    * Modan: Fixed!
* Modan's -- Tetration: Math, ad-hoc
  * Modan: Just find pattern or prove simple formula. Hopefully people can figure it out. It's hard to judge the solving rate of this problem.
  * Howard: I wonder if binary search can be used for this problem instead?
  * Modan: Interestingly enough binary search gives quite a different result from "the formula". The absolute error is up to ~0.05. I think this is due to floating point precision error when approximating tetration. I'm not 100% sure but I want to say using "pow()" 10,000 times on top of one another introduces quite a bit of error. This problem does feel too much like something straight out of a math contest.
* Wenli's -- Quantum Superposition: DAG, sets
* Zac's -- Musical Scales: ad-hoc
* Zac's -- Maximal Sequences
* Howard's -- Lane Switching
  * Wenli: Is is guaranteed that the ACM car is in the leftmost lane, there are no other cars in the leftmost lane, and that cars will not extend outside of the sensor's range?

### FAQ

* Is there a graceful way of handling float-point roundoff in the answer on kattis?
  * Yes, e.g. to add 1e-6 absolute or relative tolerance, add "validator_flags: float_tolerance 1e-6" to problem.yaml
* Are you preferring one test file with many cases, or each test case in its own file? I can adjust these problems to match others for consistency.
  * Wenli: I think we can do both, author can decide. One test case would be easier for contestants if possible.
