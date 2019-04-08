// TODO - set up sending/receiving with client using sfml
// TODO - find a way to detect when a client has disconnected
#pragma once

//#define SFML_STATIC

#include <SFML/Network.hpp>
#include <SFML/System/Time.hpp>

#ifdef MWMUD_DEBUG
#pragma comment (lib, "sfml-network-d.lib")
#pragma comment (lib, "sfml-system-d.lib")
#endif

#ifdef MWMUD_RELEASE
#pragma comment(lib, "sfml-system.lib")
#pragma comment(lib, "sfml-network.lib")
#endif

#include <unordered_set>
#include <stack>

class ServerNetwork
{
private:
	sf::TcpListener listener;	// listens for incoming connections
	std::unordered_set<sf::TcpSocket*> clients;	// clients connected to server
	bool running = false;

	void broadcastPacket(sf::Packet);

public:
	static const int MAX_CONNECTIONS = 8;

	// initialize the server
	bool init();
	// Set the server as running or not
	void setRunning(bool);
	// Return whether the server is running or not
	bool isRunning();
	// check for server events
	void pollEvents();
	
	// clean up, shut down
	void cleanup();
};
