/*
 *   part of this code is origined from
 *   GOGO-no-coda
 *
 *   Copyright(C) 2001,2002,2003 T.Narita
 *   Copyright(C) 2001,2002,2003 gogo-developer
 */


#ifndef __FILEHEAD_H__
#define __FILEHEAD_H__


//	RIFF ����Ƭ�Υ���󥯥إå�
struct CK_RIFF {
	long	chunk;						/* "RIFF" */
	long	size;						/* sizeof "RIFF" */
	long	form;						/* "WAVE" or etc */
} ;

//	RIFF/WAVE �� fmt �����
struct CK_FMT {
	long	chunk;						/* "fmt " */
	long	size;						/* 30 */
	short	formatID;					/* 0x55 = WAVE_FORMAT_MPEGLAYER3 */
	short	num_of_channel;				/* 1 or 2 */
	long	srate;						/* 44100 etc. */
	long	avg_bytes_per_sec;			/* ʿ�ѥӥåȥ졼��(�Х���/��) */
	short	block_size;					/* 1 */
	short	bits_per_sample;			/* 0 */
	short	cbSize;						/* 12 */
	short 	wID;						/* 1 = MPEGLAYER3_ID_MPEG */
	long	fdwFlags;					/* 2 */
  	short	nBlockSize;					/* �ե졼��ΥХ��ȿ� */
  	short	nFramesPerBlock;			/* 1 */
  	short	nCodecDelay;				/* ?? */
} ;

//	RIFF/WAVE �� fact �����
struct CK_FACT {
	long	chunk;						/* "fact" */
	long	size;						/* 4 */
	long	num_of_sample;				/* ����ץ�� */
} ;

//	RIFF �� data ����󥯤Υإå�
struct CK_DATA {
	long	chunk;						/* "data" */
	long	size;						/* sizeof "DATA" */
} ;

//	RIFF/WAVE �� mp3 ���Τ��������ʬ
struct CK_WAVE {
	struct	CK_RIFF		riff;
	struct	CK_FMT		fmt;
	struct  CK_FACT		fact;
	struct	CK_DATA		data;
} ;

//	RIFF/RMP �� mp3 ���Τ��������ʬ
struct CK_RMP {
	struct	CK_RIFF		riff;
	struct	CK_DATA		data;
};

//	RIFF �� LIST ����󥯤Υإå�
struct CK_LIST {
	long	chunk;						/* "LIST" */
	long	size;						/* sizeof "LIST" */
	long	form;						/* "INFO" etc */
} ;

//	�ƥ���󥯹�¤�Τη��̵���ΥХ��ȿ�
#define	SizeOfCkRiff	(12)
#define	SizeOfCkFmt	(38)
#define	SizeOfCkFact	(12)
#define	SizeOfCkData	(8)
#define	SizeOfCkWave	(SizeOfCkRiff+SizeOfCkFmt+SizeOfCkFact+SizeOfCkData)
#define	SizeOfCkRmp	(SizeOfCkRiff+SizeOfCkData)
#define	SizeOfCkList	(12)

#endif /* __FILEHEAD_H__ */