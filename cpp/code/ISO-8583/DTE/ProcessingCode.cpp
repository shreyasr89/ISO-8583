/*
 * ProcessingCode.cpp
 *
 *  Created on: 17 mai 2015
 *      Author: FrancisANDRE
 */

#include "ISO-8583/DTE/ProcessingCode.h"

namespace ISO_8583 {
	namespace DTE {
		const char* TransactionCode[] = {
			// Debits: 00-1Z
			"00",	// Goods and service (Buy)
			"01",	// Cash (ATM)
			"02",	// Adjustment
			"03",	// Cheque guarantee (funds guaranteed)
			"04",	// Cheque verification (funds available but not guaranteed)
			"05",	// Eurocheque
			"06",	// Traveller cheque
			"07",	// Letter of credit
			"08",	// Giro (postal banking)
			"09",	// Goods and services with cash disbursement
			"10",	// Non-cash financial instrument, e.g. wire transfer
			"11",	// Quasi-cash and scrip
			"12",	// Cash (manual)
			"13",	// Funds withdrawal for electronic purse; unlinked loads to funds issuer
			"14",	// Benefits purchase with cash-back
			"15",	// Benefit cash withdrawal
			"16",	// Benefit cash purchase
			"17",	// Funds withdrawal for electronic purse; unlinked unloads to card issuer
			//18-1J Reserved for ISO use
			//1K-1R Reserved for national use
			//1S-1Z Reserved for private use

			// Credits: 20-2Z 
			"20",	// Returns
			"21",	// Deposits
			"22",	// Adjustment
			"23",	// Cheque deposit guarantee
			"24",	// Cheque deposit
			"25",	// Deposit with cash-back
			"26",	// Cheque deposit with cash-back
			"27",	// Funds deposit from electronic purse; unlinked unloads to funds issuer
			"28",	// Funds deposit from electronic purse; unlinked loads to card issuer
			"29",	// Original credit e.g. wire transfer, gaming wins
			//2A-2J Reserved for ISO use
			//2K-2R Reserved for national use
			//2S-2Z Reserved for private use

			// Inquiry/Verification services: 30-3Z
			"30",	// Available funds inquiry
			"31",	// Balance inquiry
			"32",	// Ledger balance inquiry
			"33",	// Verification inquiry
			"34",	// Statement inquiry
			"35",	// Cleared item inquiry
			"36",	// Cash balance inquiry
			//37-3J Reserved for ISO use
			//3K-3R Reserved for national use
			//3S-3Z Reserved for private use

			// Transfer services: 40-4Z
			"40",	// Cardholder accounts transfer
			//41-4J Reserved for ISO use
			//4K-4R Reserved for national use
			//4S-4Z Reserved for private use

			// Payment services: 50-5Z
			"50",	// Customer generated/initiated payment
			"51",	// Account verification
			"52",	// Payment return
			//53-5J Reserved for ISO use
			//5K-5R Reserved for national use
			//5S-5Z Reserved for private use

			// Electronic purse services: 60-6Z
			"60",	// Load value; linked loads
			"61",	// Unload value; linked unloads
			"62",	// Transfer value
			"63",	// Administrative
			"64",	// Currency exchange
			//65-6J Reserved for ISO use
			//6K-6R Reserved for national use
			//6S-6Z Reserved for private use

			// Administrative: 70-7Z
			"70",	// Pin change
			"71",	// PIN verify
			"72",	// Activation
			//7K-7R Reserved for national use
			//7S-7Z Reserved for private use

			// Reserved: 80-8Z
			//80-8J Reserved for ISO use
			//8K-8R Reserved for national use
			//8S-8Z Reserved for private use

			// Reserved: 90-9Z
			//90-9J Reserved for ISO use
			//9K-9R Reserved for national use
			//9S-9Z Reserved for private use
		};
		const char* DebitAccountCode[] = {
			"00",
			"10",
			"11",
			"12",
		};
		const char* CreditAccountCode[] = {
			"00",
			"10",
			"11",
			"12",
		};
		ProcessingCode::ProcessingCode() {
		}

		ProcessingCode::ProcessingCode(TransactionType transactionType, DebitAccountType debit, CreditAccountType credit) {
#if STD_CB2A == 150
			Numeric<2>*	tra = (Numeric<2>*)(static_cast<Numeric<6>*>(this));
			Numeric<2>*	deb = (Numeric<2>*)(tra + 1);
			Numeric<2>*	cre = (Numeric<2>*)(deb + 1);

#elif STD_ISO_8583 == 1987 || STD_ISO_8583 == 1993
			Numeric<2>*	tra = (Numeric<2>*)(static_cast<Numeric<6>*>(this));
			Numeric<2>*	deb = (Numeric<2>*)(tra + 1);
			Numeric<2>*	cre = (Numeric<2>*)(deb + 1);

#elif STD_ISO_8583 == 2003
			AlphaNumeric<2>*	tra = (AlphaNumeric<2>*)(static_cast<AlphaNumeric<6>*>(this));
			AlphaNumeric<2>*	deb = (AlphaNumeric<2>*)(tra + 1);
			AlphaNumeric<2>*	cre = (AlphaNumeric<2>*)(deb + 1);
#endif
			*tra = TransactionCode[static_cast<int>(transactionType)];
			*deb = DebitAccountCode[static_cast<int>(debit)];
			*cre = CreditAccountCode[static_cast<int>(credit)];
		}
		ProcessingCode:: ~ProcessingCode() {
		}
		SERIALIZE(ProcessingCode)
		string ProcessingCode::toString() const {
			string s(str());
			return s;
		}
	}
}