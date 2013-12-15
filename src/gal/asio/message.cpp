#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <gal/asio/message.h>

gal::asio::message::message(): body_length_(0)
{
}
const char*		gal::asio::message::data() const
{
	return data_;
}
char*			gal::asio::message::data()
{
	return data_;
}
std::size_t		gal::asio::message::length() const
{
	return header_length + body_length_;
}
const char*		gal::asio::message::body() const
{
	return data_ + header_length;
}
char*			gal::asio::message::body()
{
	return data_ + header_length;
}
std::size_t		gal::asio::message::body_length() const
{
	return body_length_;
}
void			gal::asio::message::body_length(std::size_t new_length)
{
	body_length_ = new_length;
	if (body_length_ > max_body_length)
	{
		body_length_ = max_body_length;
	}
}
bool			gal::asio::message::decode_header()
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
void			gal::asio::message::encode_header()
{
	//char header[header_length + 1] = "";
	//std::sprintf(header, "%4d", int(body_length_));
	std::memcpy(data_, (void*)&body_length_, header_length);
}






