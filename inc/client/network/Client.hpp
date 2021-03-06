/*
** EPITECH PROJECT, 2019
** Client.hpp
** File description:
** Object that manage connection to server
*/

#ifndef CLIENT_HPP_
#define CLIENT_HPP_

#include <SFML/Network.hpp>
#include "client/network/ClientError.hpp"
#include "client/graphic/Game.hpp"
#include "server/data_struct.hpp"
#include <functional>

sf::Packet& operator<<(sf::Packet&, const playerRegister&);
sf::Packet& operator>>(sf::Packet&, playerRegister&);
sf::Packet& operator<<(sf::Packet&, const Movement&);
sf::Packet& operator>>(sf::Packet&, Movement&);

class Client
{
public:
    Client();
    ~Client();
    void connect(const sf::IpAddress &adresse, unsigned short port, const std::string &name, game_t game);
    void send(const std::string &msg);
    std::string wait_start();
    void init();
    uint get_id();
    void received();
    void interpreter(const std::string &msg);
    void setCallback(std::function<void(game_t)> cb);
    bool is_connected();
    void move(uint x, uint y);
    void shoot(Direction dir);
private:
    sf::TcpSocket _socket;
    bool _is_connected;
    std::function<void(game_t)> cb;
    int nb_player;
    game_t game;
};

#endif
