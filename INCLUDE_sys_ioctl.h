/*
 ioctl.h 
 for QDOS sockets. 
 Researched from GNU headers Jonathan Hudson
 */

/*-
 * Copyright (c) 1982, 1986, 1990 The Regents of the University of California.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 * 3. All advertising materials mentioning features or use of this software
 *    must display the following acknowledgement:
 *	This product includes software developed by the University of
 *	California, Berkeley and its contributors.
 * 4. Neither the name of the University nor the names of its contributors
 *    may be used to endorse or promote products derived from this software
 *    without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE REGENTS AND CONTRIBUTORS ``AS IS'' AND
 * ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED.  IN NO EVENT SHALL THE REGENTS OR CONTRIBUTORS BE LIABLE
 * FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
 * DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS
 * OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
 * HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
 * LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY
 * OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF
 * SUCH DAMAGE.
 *
 *	@(#)ioctl.h	7.19 (Berkeley) 6/26/91
 */

#ifndef	SYS_IOCTL_H
#define	SYS_IOCTL_H

/*
 * Ioctl's have the command encoded in the lower word, and the size of
 * any in or out parameters in the upper word.  The high 3 bits of the
 * upper word are used to encode the in/out status of the parameter.
 */

#define	IOCPARM_MASK	0x1fff		/* parameter length, at most 13 bits */
#define	IOCPARM_LEN(x)	(((x) >> 16) & IOCPARM_MASK)
#define	IOCBASECMD(x)	((x) & ~IOCPARM_MASK)
#define	IOCGROUP(x)	(((x) >> 8) & 0xff)

#define	IOCPARM_MAX	4096		/* max size of ioctl */
#define	IOC_VOID	0x20000000	/* no parameters */
#define	IOC_OUT		0x40000000	/* copy out parameters */
#define	IOC_IN		0x80000000	/* copy in parameters */
#define	IOC_INOUT	(IOC_IN|IOC_OUT)
#define	IOC_DIRMASK	0xe0000000	/* mask for IN/OUT/VOID */

#define _IOC(inout,group,num,len) \
	(inout | ((len & IOCPARM_MASK) << 16) | ((group) << 8) | (num))
#define	_IO(g,n)	_IOC(IOC_VOID,	(g), (n), 0)
#define	_IOR(g,n,t)	_IOC(IOC_OUT,	(g), (n), sizeof(t))
#define	_IOW(g,n,t)	_IOC(IOC_IN,	(g), (n), sizeof(t))
/* this should be _IORW, but stdio got there first */
#define	_IOWR(g,n,t)	_IOC(IOC_INOUT,	(g), (n), sizeof(t))

/* 
 * file i/o controls
 */
    
/* 
 * socket i/o controls
 *
 * SIOCSPGRP and SIOCGPGRP are identical to the FIOSETOWN and FIOGETOWN,
 * respectively.
 */
#define	SIOCATMARK	_IOR('s',  7, long)    /* at oob mark? */
#define	SIOCSPGRP	_IOW('s',  8, long)    /* set process group */
#define	SIOCGPGRP	_IOR('s',  9, long)    /* get process group */

#define	SIOCADDRT	_IOW('r', 10, struct ortentry) /* add route */
#define	SIOCDELRT	_IOW('r', 11, struct ortentry) /* delete route */

#define	SIOCSIFADDR	_IOW('I', 12, struct ifreq)    /* set ifnet address */
#define	OSIOCGIFADDR	_IOWR('I',13, struct ifreq)    /* get ifnet address */
#define	SIOCGIFADDR	_IOWR('I',33, struct ifreq)    /* get ifnet address */
#define	SIOCSIFDSTADDR	_IOW('I', 14, struct ifreq)    /* set p-p address */
#define	OSIOCGIFDSTADDR	_IOWR('I',15, struct ifreq)    /* get p-p address */
#define	SIOCGIFDSTADDR	_IOWR('I',34, struct ifreq)    /* get p-p address */
#define	SIOCSIFFLAGS	_IOW('I', 16, struct ifreq)    /* set ifnet flags */
#define	SIOCGIFFLAGS	_IOWR('I',17, struct ifreq)    /* get ifnet flags */
#define	OSIOCGIFBRDADDR	_IOWR('I',18, struct ifreq)    /* get broadcast addr */
#define	SIOCGIFBRDADDR	_IOWR('I',35, struct ifreq)    /* get broadcast addr */
#define	SIOCSIFBRDADDR	_IOW('I',19, struct ifreq)     /* set broadcast addr */
#define	OSIOCGIFCONF	_IOWR('I',20, struct ifconf)   /* get ifnet list */
#define	SIOCGIFCONF	_IOWR('I',36, struct ifconf)   /* get ifnet list */
#define	OSIOCGIFNETMASK	_IOWR('I',21, struct ifreq)    /* get net addr mask */
#define	SIOCGIFNETMASK	_IOWR('I',37, struct ifreq)    /* get net addr mask */
#define	SIOCSIFNETMASK	_IOW('I',22, struct ifreq)     /* set net addr mask */
#define	SIOCGIFMETRIC	_IOWR('I',23, struct ifreq)    /* get IF metric */
#define	SIOCSIFMETRIC	_IOW('I',24, struct ifreq)     /* set IF metric */
#define	SIOCDIFADDR	_IOW('I',25, struct ifreq)     /* delete IF addr */
#define	SIOCAIFADDR	_IOW('I',26, struct ifaliasreq)	/* add/chg IF alias */


#define	SIOCSARP	_IOW('I', 30, struct arpreq)   /* set arp entry */
#define	OSIOCGARP	_IOWR('I',31, struct arpreq)   /* get arp entry */
#define	SIOCGARP	_IOWR('I',38, struct arpreq)   /* get arp entry */
#define	SIOCDARP	_IOW('I', 32, struct arpreq)   /* delete arp entry */

/*
 * A private extension to the BSD44 ioctl interface
 */
#define SIOCSSANATAGS   _IOW('I',64, struct wiretype_parameters) 
#define SIOCGSANATAGS   _IOR('I',65, struct wiretype_parameters)
/* Get arp table addr */
#define SIOCGARPT       _IOWR('I',66, struct arptabreq)   

#endif /* !SYS_IOCTL_H */
