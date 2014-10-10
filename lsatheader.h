/*************************
header file for lsatmain.c
*************************/

/* these are in lsatmain.c itself... */
void usage();
int findexclude(char xlisting[], int *xlist);
int versions(char release[], char kernel[], int verbose);
int lsatrm(void);
/* end of list of funcs inside lsatmain.c itself */

/* dostuff does all sortfs of stuff, read it for details. */
int dostuff(const char *const tempfile, const char *const outfile, const char *const shellcode, const char *const header, int html);

/* checks rpms against a list of unnecessary ones */
int checkpkgs(int distribution, const char *const filename, int verbose, int html);

/* check /etc/inetd.conf file for entries.	  */
/* if running xinetd.d, check that.		  */
int checkinetd(const char *const outfile, int distribution, int verbose, int html);

/* check that the default runlevel is not set to 5 */
int checkinittab(const char *const outfile, int distribution, int verbose, int html);

/* if running inetd or xinetd.d, check that 	  */
/* hosts.deny has ALL:ALL, at least.		  */
int checkhostsfiles(const char *const outfile, int verbose, int html);

/* check for auth and authpriv facilities    */
int checklogging(const char *const outfile, int distribution, int verbose, int html);

/* check rpm integrity, only run if -r switch given */
int checkrpm(const char *const outfile, int verbose, int html);

/* check SETUID/SETGID files on the sustem	  */
int checkset(const char *const outfile, int verbose, int html);

/* check for world WRITABLE files and directories */
int checkwrite(const char *const outfile, int distribution, int verbose, int html);

/* check for .exrc and .forward files */
int checkdotfiles(const char *const outfile, int verbose, int html);

/* check for UID 0 other than root and unwated users */
int checkpasswd(const char *const outfile, int distribution, int verbose, int html);

/* check for sticky bits on /tmp, /var/tmp */
/* this will do more later. */
int checkfiles(const char *const outfile, int verbose, int html);

/* check for umask settings in /etc/ */
int checkumask(const char *const outfile, int verbose, int html);

/* check for entries in /etc/ftpusers */
int checkftpusers(const char *const outfile, int verbose, int html);

/* check for errors in ftp configs... */
int checkftp(const char *const outfile, int verbose, int distribution, int html);

/* check rc files for unneeded ones */
int checkrc(char release[], char kernel[], int distribution, const char *const outfile, int verbose, int html);

/* check for ctrl-alt-del (linux) or STOP-A (SunOS) disable */
int checkkbd(char release[], const char *const outfile, int verbose, int html);

/* check for limits.conf file */
int checklimits(const char *const outfile, int verbose, int html);

/* check for sshd config errors */
int checkssh(const char *const outfile, int distribution, int verbose, int html);

/* check network ports we are listening on */
int checknet(const char *const outfile, int distribution, int verbose, int html);

/* check for network forwarding */
int checknetforward(const char *const outfile, int distribution, int verbose, int html);

/* print out all daemons in all runlevels for the user to inspect */
/* this is a redhat (and derivative) specific module...		  */
int checkcfg(const char *const outfile, int verbose, int html);

/* do a lsof check. See checkopenfiles for details. */
/* this module will be expanded later on. 	    */
int checkopenfiles(const char *const outfile, int distribution, int verbose, int html);

/* this will check for /etc/issue and /etc/issue.net */
/* see the module for more details */
int checkissue(const char *const outfile, int verbose, int html);

/* this checks for execcgis... should also check for SSIs later */
int checkwww(const char *const outfile, int distribution, int verbose, int html);

/* this checks to see if kernel modules are enabled */
int checkmodules(const char *const outfile, int verbose, int html);

/* this gives a list of all md5sums of all files on the system */
/* if run previously, the old list is called lsatmd5.old, the  */
/* list generated by checkmd5 is called lsatmd5.out...         */
int checkmd5(const char *const outfile, int distribution, int verbose, int html, int diff);

/* check /etc/securetty for entries... */
int checksecuretty(const char *const outfile, int verbose, int html);

/* check that files in /etc/rc.d/init.d are perm 700 */
int checkrcperms(const char *const outfile, int distribution, int verbose, int html);

/* check that the network interfaces are not in promisc mode */
int checknetp(char kernel[], const char *const outfile, int distribution,  int verbose, int html);

/* check that the bootloaders are using passwords */
int checkbpass(int distribution, const char *const outfile, int verbose, int html);

/* check some ipv4 stuffs in /proc */
int checkipv4(const char *const outfile, int verbose, int html);

/* check to see if X is listening for tcp connections */
int checkx(const char *const outfile, int verbose, int html);

/* Check for listening apps. See checklistening for details. */
/* will this module ever be expanded later on? 	    */
int checklistening(const char *const outfile, int distribution, int verbose, int html);

/* perform some very basic disk checking, like mounted */
/* filesystems and current disk usage. Will expand this later */
int checkdisk(const char *outfile, int verbose, int html);

/* try to list all of the services that start at boot time */
int checkservices(const char *const outfile, int distribution, int verbose, int html);

/* check to list what packages would be updated if you ran an update */
int checkpkgupdate(const char *const outfile, int distribution, int verbose, int html);

/* check for users on the system and print out the password expiration */
int checkpasstime(const char *const outfile, int distribution, int verbose, int html);