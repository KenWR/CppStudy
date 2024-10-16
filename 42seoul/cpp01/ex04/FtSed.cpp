#include "FtSed.hpp"
#include <string>
#include <iostream>

const std::string& FtSed::GetSrc( void ) const {
	return (this->src_);
}

const std::string&	FtSed::GetDest( void ) const {
	return (this->dest_);
}

void FtSed::SetSrc( const std::string& str ) {
	this->src_ = str;
}

void FtSed::SetDest( const std::string& str ) {
	this->dest_ = str;
}

void FtSed::srcToDest( std::string& str ) {
	size_t pos = str.find(this->src_);
	while (pos != std::string::npos) {
		std::string lstr = str.substr(0, pos);
		std::string rstr = str.substr(pos + this->src_length_, str.length());
		str = lstr + this->dest_ + rstr;
		pos = str.find(this->src_);
	}
}

FtSed::FtSed( std::string& src, std::string& dest ) : src_(src), dest_(dest) {
	this->src_length_ = src.length();
	this->dest_length_ = dest.length();
}

FtSed::FtSed( const FtSed& copy ) : src_(copy.src_), dest_(copy.dest_) {
	*this = copy;
}

FtSed& FtSed::operator = ( const FtSed& src ) {
	if (this != &src) {
		this->src_ = src.src_;
		this->dest_ = src.dest_;
	}

	return (*this);
}

FtSed::~FtSed() {

}


