#ifndef _H_WMB_ASM_SDK_INET
#define _H_WMB_ASM_SDK_INET

struct EthernetHeader//Ethernet II/2 header, as seen in Wireshark
{
    unsigned char src[6];
    unsigned char dst[6];
    unsigned short type;
} __attribute__ ((__packed__));

struct IPHeader
{
    /*#if __BYTE_ORDER == __BIG_ENDIAN
    unsigned char version:4, length:4;//Previously this line just had unsigned char verlen
    #endif
    #elif  __BYTE_ORDER == __LITTE_ENDIAN*/
    unsigned char length:4, version:4;//Previously this line just had unsigned char verlen
    /*#endif
    #else
    # error "Please fix <bits/endian.h>"
    #endif*/
    
    unsigned char diff_services;
    unsigned short total_length;
    unsigned short id;
    unsigned short flags_fragment;
    unsigned char time_to_live;
    unsigned char protocol;
    unsigned short header_checksum;
    unsigned int src;
    unsigned int dst;
} __attribute__ ((__packed__));

EthernetHeader *CheckGetEthernet(unsigned char *data, int length, unsigned short type = 0);
unsigned char *GetEthernet(unsigned char *data, int length, unsigned short type = 0);

IPHeader *CheckGetIP(unsigned char *data, int length);
unsigned char *GetIP(unsigned char *data, int length);

#endif
