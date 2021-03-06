/*
** EPITECH PROJECT, 2019
** Server.hpp
** File description:
** 
*/

#ifndef SERVER_HPP_
#define SERVER_HPP_

#include <SFML/Network.hpp>
#include "server/ServerError.hpp"
#include "server/ServerPlayer.hpp"
#include "server/data_struct.hpp"
#include <thread>

class Server
{
public:
    Server();
    ~Server();
    void start(unsigned short port);
    void connecting_player();
    void process();
    void interpreter(const std::string &msg, uint i);
    void connection_info(const std::string &msg);
    void start_game();
    void init();
    void send_id();
    void send_all(const std::string &msg);
    void new_player(const std::string &name, uint idx);
    void player_move(const std::string &args, uint idx);
    void send_all(sf::Packet packet);
    void handle_shoot(Movement shot, uint idx);
    void player_get_shot(int i);
private:
    sf::TcpListener listener;
    Vec spawn_blue;
    Vec spawn_red;
    std::vector<sf::TcpSocket *> clients;
    std::vector<Ply> players;
    sf::SocketSelector selector;
    bool connectingPlayer;
    bool serverOn;
};

sf::Packet& operator<<(sf::Packet &packet, const Movement&m);
sf::Packet& operator>>(sf::Packet &packet, Movement &m);
sf::Packet& operator>>(sf::Packet& packet, playerRegister& m);
sf::Packet& operator<<(sf::Packet& packet, const playerRegister& m);

#endif
