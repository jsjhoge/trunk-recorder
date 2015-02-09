#ifndef P25_PARSE_H
#define P25_PARSE_H
#include "parser.h"
#include <iostream>
#include <iomanip>
#include <map>
#include <vector>
#include <boost/dynamic_bitset.hpp>
#include <gnuradio/message.h>
#include <bitset>

struct Channel {
	long id;
	long offset;
	long step;
	long frequency;
	int tdma;
};

class P25Parser:public TrunkParser
{
		std::map<int,Channel> channels;
	 	std::map<int,Channel>::iterator it;
public:
 P25Parser();
 long get_tdma_slot(int chan_id);
 TrunkMessage decode_tsbk(boost::dynamic_bitset<> &tsbk);
 unsigned long bitset_shift_mask(boost::dynamic_bitset<> &tsbk, int shift, unsigned long long mask);
 std::string  channel_id_to_string(int chan_id);
 void print_bitset(boost::dynamic_bitset<> &tsbk);
 void add_channel(int chan_id, Channel chan);
 double channel_id_to_frequency(int chan_id);
 TrunkMessage parse_message(gr::message::sptr msg);
};

#endif