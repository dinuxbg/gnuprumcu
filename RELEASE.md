# Release Procedure

 1. Bump version in configure.ac
 2. Add debian log entry:

	dch

 3. Test the packaging:

	make distcheck

 4. Run the testsuite:

	make check

 5. Install and test different `-mmcu=` values in some PRU example project.
 6. Wait a few hours for the [mirror](https://git.beagleboard.org/beagleboard/gnuprumcu/-/pipelines) on BeagleBoard to sync, and CI pipeline to finish. Ensure all stages are passing.
 7. Create and push a tag.
