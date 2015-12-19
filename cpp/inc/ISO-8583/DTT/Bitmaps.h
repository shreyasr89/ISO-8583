/*
 * Bitmaps.h
 *
 *  Created on: 8 juin 2015
 *      Author: FrancisANDRE
 */

#ifndef BITMAPS_H_
#define BITMAPS_H_
#include <iostream>
#include <bitset>
using  std::ostream;
using  std::istream;
using  std::bitset;

#include "ISO-8583-DTT.h"
#include "ISO-8583/DTT/InputStream.h"
#include "ISO-8583/DTT/OutputStream.h"
/*
Bit Cons Comp Name Format Representation
1						Continuation						bit		b 8
2						Primary account number (PAN)		LLVAR	n..19
3	X					Processing code								an 6
	3-1					Transaction type code						an 2
	3-2					Account type code 1							an 2
	3-3					Account type code 2							an 2
4	X					Amount transaction							n 16
	4-1 Currency code amount transaction n 3
	4-2 Currency minor unit amount transaction n 1
	4-3 Value amount transaction n 12
5 X Amount reconciliation n 16
5-1 Currency code amount reconciliation n 3
5-2 Currency minor unit amount reconciliation n 1
5-3 Value amount reconciliation n 12
6 X Amount cardholder billing n 16
6-1 Currency code amount cardholder billing n 3
6-2 Currency minor unit amount cardholder
billing
n 1
6-3 Value amount cardholder billing n 12
7 Date and time transmission MMDDhhmmss n 10
8 X Amount cardholder billing fee n 12
8-1 Currency code amount cardholder billing
fee
n 3
8-2 Currency minor unit amount cardholder
billing fee
n 1
8-3 Value amount cardholder billing fee n 8
9 Conversion rate reconciliation n 8
10 Conversion rate cardholder billing n 8
11 Systems trace audit number n 12
12 X Date and time local transaction CCYYMMDDhhmmss n 14
12-1 Date local transaction CCYYMMDD n 8
12-2 Time local transaction hhmmss n 6
13 Date effective CCYYMM n 6
14 Date expiration YYMM n 4
15 Date settlement CCYYMMDD n 8
16 Date conversion MMDD n 4
17 Date capture MMDD n 4
18 X Message error indicator LLLVAR ansb..140
18-1 Error severity code n 2
18-2 Message error code n 4
18-3 Data element in error n 3
18-4 Data sub-element in error n 2
18-5 Dataset identifier in error b 1
18-6 Dataset bit or tag in error b 2
19 Country code acquiring institution n 3
20 Country code primary account number (PAN) n 3
21 X Transaction life cycle identification data ans 22
21-1 Life cycle support indicator ans 1
21-2 Life cycle trace identifier ans 15
21-3 Life cycle transaction sequence number n 2
21-4 Life cycle authentication token n 4
22 X POS data code b 16
22-1 Card reading method used at POS b 4
22-2 Cardholder verification method used at POS b 4
22-3 POS environment b 4
22-4 Security characteristics b 4
23 Card sequence number n 3
24 Function code n 3
25 Message reason code n 4
26 Merchant category code n 4
27 X POS capability anb 27
27-1 POS card reading capability b 4
27-2 POS cardholder verification capability b 4
27-3 Approval code length n 1
27-4 Cardholder receipt data length n 3
27-5 Card acceptor receipt data length n 3
27-6 Cardholder display data length n 3
27-7 Card acceptor display data length n 3
27-8 ICC scripts data length n 3
27-9 Magnetic stripe track 3 rewrite capability a 1
27-10 Card capture capability a 1
27-11 Pin input length capability b 1
28 Date reconciliation CCYYMMDD n 8
29 Reconciliation indicator n 3
30 X Amounts original n 32
30-1 Original amount transaction n 16
30-1.1 Currency code original amount transaction n 3
30-1.2 Currency minor unit original amount
transaction
n 1
30-1.3 Value original amount transaction n 12
30-2 Original amount reconciliation n 16
30-2.1 Currency code original amount reconciliation n 3
30-2.2 Currency minor unit original amount
reconciliation
n 1
30-2.3 Value original amount reconciliation n 12
31 Acquirer reference number n 23
31-1 User format identifier n 1
31-2 Acquirer number n 6
31-3 Julian processing date YDDD n 4
31-4 Sequence number n 11
31-5 Luhn check digit n 1
32 Acquiring institution identification code LLVAR n..11
33 Forwarding institution identification code LLVAR n..11
34 X Electronic commerce data LLLLVAR b..9999
34-71 Account based digital signature LLVAR b..90
34-72 Authentication code Tag 80 ansb..50
34-72 Card acceptor certificate serial number LLVAR b..16
34-72 Cardholder certificate serial number LLVAR b..16
34-72 TransStain b 20
34-72 XID b 20
35 Track 2 data LLVAR z..37
36 Track 3 data LLLVAR z..104
37 Retrieval reference number anp 12
38 Approval code anp 6
39 Action code n 4
40 Service code n 3
41 Card acceptor terminal identification ans 16
42 Card acceptor identification code LLVAR ans..35
43 X Card acceptor name/location LLLLVAR ansb..9999
43-71 Card acceptor additional address
information
Tag 81 an..256
43-71 Card acceptor additional contact information LLVAR ans..30
43-71 Card acceptor city LLVAR ans..50
43-71 Card acceptor country code a 3
43-71 Card acceptor customer service phone
number
ans 16
43-71 Card acceptor e-mail address LLVAR ans..99
43-71 Card acceptor internet URL LLLVAR ans..255
43-71 Card acceptor name LLVAR ans..50
43-71 Card acceptor phone number ans 16
43-71 Card acceptor postal code ans 10
43-71 Card acceptor state province or region code ans 3
43-71 Card acceptor street address LLVAR ans..99
44 X Additional response data LLLLVAR ansb..9999
44-71 Card acceptor display data LLVAR ans. 99
44-71 Card acceptor receipt data LLVAR ans..99
44-71 Card issuer telephone number ans 16
44-71 Cardholder receipt data LLVAR ans..99
44-71 Cardholder display data LLVAR ans..99
45 Track 1 data LLVAR ans..76
46 X Amounts fees LLLVAR ans..216
46-1 Fee type code n 2
46 –2 Amount fee xn 13
46-2.1 Currency code amount fee n 3
46-2.2 Currency minor unit amount fee n 1
46-2.3 Value amount fee n 8
46-3 Conversion rate fee n 8
46-4 Amount reconciliation fee xn 13
46-4.1 Currency code amount reconciliation fee n 3
46-4.2 Currency minor unit reconciliation fee n 1
46-4.3 Value reconciliation fee n 8
47 Additional data national LLLVAR ans..999
48 Additional data private LLLVAR ans..999
49 X Verification data LLLLVAR ans..9999
49-71 Additional identification reference number LLVAR ans..30
49-71 Additional identification type n 1
49-71 Card verification data n 4
49-71 Cardholder billing address compressed ans 16
49-71 Cardholder billing postal code ans 10
49-71 Cardholder billing street address ans 40
49-72 Address verification result code an 1
50-51 Reserved for ISO LLLVAR ansb..9999 a
52 PIN data b 8
53 Security related control information LLVAR b..48
54 X Amounts additional LLLVAR ans..126
54-1 Account type additional amounts an 2
54-2 Amount type additional amounts an 2
54-3 Amount additional amounts xn 17
54-3.1 Currency code amount additional amounts n 3
54-3.2 Currency minor unit amount additional
amounts
n 1
54-3.3 Value amount additional amounts n 12
55 X ICC system related data LLLLVAR b..9999
56 X Original data elements LLVAR n..41
56-1 Original message type identifier n 4
56-2 Original system trace audit number n 12
56-3 Original date and time local transaction CCYYMMDDhhmmss n 14
56-4 Original acquiring institution identification
code
n..11
57 Authorization life cycle code n 3
58 Authorizing agent institution identification
code
LLVAR n..11
59 Transport data LLLVAR ans..999
60-61 Reserved for national use LLLVAR ans..999 a
62-63 Reserved for private use LLLVAR ans..999 a
64 or 128 MAC field b 4
*/
namespace ISO_8583 {
	namespace DTT {

		class DTT_API_SCOPE Bitmaps {
		private:
			class DTT_API_SCOPE Bitmap : private bitset < 64 > {
			public:
				explicit Bitmap();
				explicit Bitmap(int n, ...);
				~Bitmap();

				void set(byte no, bool value = true);
				void set(nat8 no);
				bool get(byte no) const;
				nat8 toLong() const { return bitset<64>::to_ullong(); }

				size_t size() const { return bitset<64>::size(); }
				size_t count() const { return bitset<64>::count(); }
				bool none() const { return bitset<64>::none(); }
				bool all() const { return bitset<64>::all(); }
				bool any() const { return bitset<64>::any(); }

				friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, Bitmaps::Bitmap& bitmap);
				friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Bitmaps::Bitmap& bitmap);
			};
		private:
			Bitmap		bitmap1;
			Bitmap		bitmap2;
			Bitmap		bitmap3;

		public:
			explicit Bitmaps();
			explicit Bitmaps(int n, ...);
			~Bitmaps();

			void set(byte no, bool value = true);
			void set(nat8 bitno1, nat8 bitno2 = 0, nat8 bitno3 = 0);
			bool get(byte no) const;
			nat8 toLong(byte no) const { 
				if (no == 1) return bitmap1.toLong(); 
				if (no == 2) return bitmap2.toLong(); 
				if (no == 3) return bitmap3.toLong(); 
				return -1;
			}

			size_t size() const { return bitmap1.size() + bitmap2.size() + bitmap3.size(); }
			size_t count() const { return bitmap1.count() + bitmap2.count() + bitmap3.count(); }
			bool none() const { return bitmap1.none() && bitmap2.none() && bitmap3.none(); }
			bool all() const { return bitmap1.all() && bitmap2.all() && bitmap3.all(); }
			bool any() const { return bitmap1.any() || bitmap2.any() || bitmap3.any(); }

			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, Bitmaps& bitmaps);
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Bitmaps& bitmaps);

			friend DTT_API_SCOPE InputStream& operator>>(InputStream& is, Bitmaps::Bitmap& bitmap);
			friend DTT_API_SCOPE OutputStream& operator<<(OutputStream& os, const Bitmaps::Bitmap& bitmap);
		};
	}
}

#endif
