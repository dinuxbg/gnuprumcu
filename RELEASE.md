# Release Procedure

 1. Bump version in configure.ac
 2. Add debian log entry:

	dch

 3. Test the packaging:

	make distcheck

 4. Install and test different -mmcu= values in some PRU example project.
 5. Git push to publish.
