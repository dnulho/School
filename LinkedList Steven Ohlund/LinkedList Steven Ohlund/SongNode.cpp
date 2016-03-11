#include <iostream>
using std::cout;
using std::endl;

#include "SongNode.h"

SongNode::SongNode(string & songTitle, string & artist)
	:m_next(nullptr), m_previous(nullptr), m_artist(artist), m_songTitle(songTitle)
{
}

SongNode::SongNode(const SongNode & copy)
	: m_next(nullptr), m_previous(nullptr), m_artist(copy.m_artist), m_songTitle(copy.m_songTitle)
{
}

SongNode & SongNode::operator=(const SongNode & rhs)
{
	m_next = nullptr;
	m_previous = nullptr;
	m_artist = rhs.m_artist;
	m_songTitle = rhs.m_songTitle;
	return *this;
}

SongNode::~SongNode()
{
}

void SongNode::Display() const
{
	DisplaySong();
	cout << "\t";
	DisplayArtist();
}

void SongNode::DisplaySong() const
{
	cout << "Song Title: " << m_songTitle.c_str() << endl;
}

void SongNode::DisplayArtist() const
{
	cout << "Artist: " << m_artist.c_str() << endl;
}