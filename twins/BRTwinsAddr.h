//
//  BRTwinsAddr.h
//
//  Created by Aaron Voisine on 9/18/15.
//  Copyright (c) 2015 breadwallet LLC
//
//  Permission is hereby granted, free of charge, to any person obtaining a copy
//  of this software and associated documentation files (the "Software"), to deal
//  in the Software without restriction, including without limitation the rights
//  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
//  copies of the Software, and to permit persons to whom the Software is
//  furnished to do so, subject to the following conditions:
//
//  The above copyright notice and this permission notice shall be included in
//  all copies or substantial portions of the Software.
//
//  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
//  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
//  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
//  AUTHORS OR COPOYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
//  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
//  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
//  THE SOFTWARE.

#ifndef BRTwinsAddr_h
#define BRTwinsAddr_h

#include "BRCrypto.h"
//#include "BRAddress.h"
#include <string.h>
#include <stddef.h>
#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif
    
#if BITCOIN_TESTNET
#pragma message "testnet build"
#endif
    
    typedef struct {
        char s[75];
    } BRTwinsAddr;
#define TWINS_PUBKEY_ADDRESS 73
#define TWINS_PUBKEY_ADDRESS_TEST 85
#define TWINS_SCRIPT_ADDRESS_TEST 125
#define TWINS_SCRIPT_ADDRESS 83
#define OPO_0           0x00
#define OPO_PUSHDATA1   0x4c
#define OPO_PUSHDATA2   0x4d
#define OPO_PUSHDATA4   0x4e
#define OPO_1NEGATE     0x4f
#define OPO_1           0x51
#define OPO_16          0x60
#define OPO_DUP         0x76
#define OPO_EQUAL       0x87
#define OPO_EQUALVERIFY 0x88
#define OPO_HASH160     0xa9
#define OPO_CHECKSIG    0xac
#define BR_ADDRESS_NONEE ((BRTwinsAddr) { "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"\
"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0" })
    const uint8_t *BRScriptDataz(const uint8_t *elem, size_t *dataLen);

    // writes the bitcoin address for a scriptPubKey to addr
    // returns the number of bytes written, or addrLen needed if addr is NULL
    size_t BRTwinsAddrFromScriptPubKey(char *addr, size_t addrLen, const uint8_t *script, size_t scriptLen);
    
    // writes the bitcoin address for a scriptSig to addr
    // returns the number of bytes written, or addrLen needed if addr is NULL
    size_t BRTwinsAddrFromScriptSig(char *addr, size_t addrLen, const uint8_t *script, size_t scriptLen);
    
    // writes the bitcoin address for a witness to addr
    // returns the number of bytes written, or addrLen needed if addr is NULL
    size_t BRTwinsAddrFromWitness(char *addr, size_t addrLen, const uint8_t *witness, size_t witLen);
    
    // writes the scriptPubKey for addr to script
    // returns the number of bytes written, or scriptLen needed if script is NULL
    size_t BRTwinsAddrScriptPubKey(uint8_t *script, size_t scriptLen, const char *addr);
    
    // returns true if addr is a valid bitcoin address
    int BRTwinsAddrIsValid(const char *addr);
    
    // writes the 20 byte hash160 of addr to md20 and returns true on success
    int BRTwinsAddrHash160(void *md20, const char *addr);
    
    // returns a hash value for addr suitable for use in a hashtable
    inline static size_t BRTwinsAddrHash(const void *addr)
    {
        return BRMurmur3_32(addr, strlen((const char *)addr), 0);
    }
    
    // true if addr and otherAddr are equal
    inline static int BRTwinsAddrEq(const void *addr, const void *otherAddr)
    {
        return (addr == otherAddr || strncmp((const char *)addr, (const char *)otherAddr, sizeof(BRTwinsAddr)) == 0);
    }
    
#ifdef __cplusplus
}
#endif

#endif // BRTwinsAddr_h
