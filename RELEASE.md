# Release Procedure

 1. Bump version in configure.ac
 2. Add debian log entry:

	dch

 3. Test the packaging:

	make distcheck

 4. Run the testsuite:

	make check

 5. Sign the release tarball:

 	gpg2 \
	  --local-user 063FD150699A4614D24A730F963DD134E821F15D \
	  --output `basename gnuprumcu-*.tar.gz`.sig \
	  --detach-sig gnuprumcu-*.tar.gz

 6. Install and test different `-mmcu=` values in some PRU example project.
 7. Create and push a tag.
 8. Upload the tarball and detached signature to Github Releases page.
