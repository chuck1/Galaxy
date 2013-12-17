#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <gal/network/message.h>

gal::network::message::message(): body_length_(0)
{
}
const char*		gal::network::message::data() const
{
	return data_;
}
char*			gal::network::message::data()
{
	return data_;
}
std::size_t		gal::network::message::length() const
{
	return header_length + body_length_;
}
const char*		gal::network::message::body() const
{
	return data_ + header_length;
}
char*			gal::network::message::body()
{
	return data_ + header_length;
}
std::size_t		gal::network::message::body_length() const
{
	return body_length_;
}
void			gal::network::message::body_length(std::size_t new_length)
{
	body_length_ = new_length;
	if (body_length_ > max_body_length)
	{
		body_length_ = max_body_length;
	}
}
bool			gal::network::message::decode_header()
{
	//char header[header_length + 1] = "";
	
	//std::strncat(header, data_, header_length);
	
	std::memcpy((void*)&body_length_, data_, header_length);
	
	//body_length_ = std::atoi(header);
	
	printf("decoded header: %X %i\n", (unsigned char)body_length_, (int)body_length_);
	
	if (body_length_ > max_body_length)
	{
		body_length_ = 0;
		return false;
	}
	
	return true;
}
void			gal::network::message::encode_header()
{
	//char header[header_length + 1] = "";
	//std::sprintf(header, "%4d", int(body_length_));
	std::memcpy(data_, (void*)&body_length_, header_length);
}






