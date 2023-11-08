/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Server.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlangloi <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 17:21:44 by mlangloi          #+#    #+#             */
/*   Updated: 2023/10/25 17:21:45 by mlangloi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_HPP
#define SERVER_HPP

#include<arpa/inet.h>
#include<netdb.h>
#include<unistd.h>
#include<netinet/in.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<stdlib.h>
#include<stdio.h>
#include<string.h>
#include<iostream>
#include<stack>
#include<vector>
#include <csignal>
#include <poll.h>
#include"../include/User.hpp"

static bool Stop = 0;

struct s_socket
{
	int fd;
	struct sockaddr_in info; 
};

class Server
{
	public:
		Server();
		~Server();
		int	InitializeServ();
		int	readMessage();
		static void	handle_signal(int signal);
		void	ConnectClient();
	
	private:
		int numConnection;
		std::vector<pollfd> * poll_fds;
		s_socket SClient;
		s_socket SServer;
		

};

#endif
