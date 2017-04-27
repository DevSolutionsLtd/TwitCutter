// Clx.h
// Define in-memory data structures for use with MS-Word .DOC Clx format

#ifndef CLX_H_INCLUDED
#define CLX_H_INCLUDED

#include <fstream>
#include "dtypes.h"
#include "FIB.h"

constexpr BYTE SET_BITS_1	= 0x00;
constexpr BYTE SET_BITS_3	= 0x00;
constexpr WORD SET_BITS_9	= 0x0000;
constexpr WORD SET_BITS_13  = 0x0000;
constexpr WORD SET_BITS_15  = 0x0000;
constexpr DWORD SET_BITS_30 = 0x00000000;

#pragma pack(push, 1)

// Sprm values
//constexpr WORD sprmCFRMarkDel = 0x0800;
//constexpr WORD sprmCFRMarkIns = 0x0801;
//constexpr WORD sprmCFFldVanish = 0x0802;
//constexpr WORD sprmCPicLocation = 0x6A03;
//constexpr WORD sprmCIbstRMark = 0x4804;
//constexpr WORD sprmCDttmRMark = 0x6805;
//constexpr WORD sprmCFData = 0x0806;
//constexpr WORD sprmCIdslRMark = 0x07;
//constexpr WORD sprmCSymbol = 0x6A09;
//constexpr WORD sprmCFOle2 = 0x080A;
//constexpr WORD sprmCHighlight = 0x2A0C;
//constexpr WORD sprmCFWebHidden = 0x0811;

struct Prl 
{
	struct Sprm
	{
		WORD ispmd : 9;
		BYTE fSpec : 1;
		BYTE sgc : 3;
		BYTE spra : 3;

		Sprm();
		~Sprm();
		
		VOID readSprm(std::ifstream&);
		

	}; // struct Sprm
	
	Prl();
	~Prl();
};

struct Clx
{
	struct Prc
	{
		BYTE clxt;
		struct PrcData
		{
			SHORT cbGrpprl;
			Prl *GrpPrl;

			PrcData();
			~PrcData();

		} data; // struct PrcData

		Prc();
		~Prc();

	} rgPrc; // struct Prc
	struct Pcdt
	{
		BYTE clxt;
		DWORD lcb;
		struct PlcPcd
		{
			DWORD *aCP;
			struct Pcd
			{
				BYTE fNoParaLast : 1;
				BYTE fR1 : 1;
				BYTE fDirty : 1;
				WORD fR2 : 13;
				struct FcCompressed
				{
					DWORD fc : 30;
					BYTE fCompressed : 1;
					BYTE r1 : 1;

					FcCompressed();
					~FcCompressed();

					VOID readFcData(std::ifstream&);
				} fc; // struct FcCompressed
				struct Prm
				{
					BYTE fComplex : 1;
					WORD data : 15;

					Prm();
					~Prm();

					VOID readPrmData(std::ifstream&);
				} prm; // struct Prm
				
				void readPcd(std::ifstream&);

				Pcd();
				~Pcd();

			} aPcd; // struct Pcd

			PlcPcd();
			~PlcPcd();

		} plcPcd; // struct PlcPcd

		Pcdt();
		~Pcdt();


		VOID readPlcPcd(std::ifstream&);
		VOID readPcdt(std::ifstream&);
	} pcdt; // struct Pcdt

	Clx();
	~Clx();

	
	VOID readToClx(std::ifstream&, DWORD);

}; // struct Clx

#pragma pack(pop)

#endif // !CLX_H_INCLUDED
