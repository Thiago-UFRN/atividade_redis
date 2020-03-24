#include <cpp_redis/cpp_redis>
#include <iostream>

typedef long long ll;
using namespace std;
using namespace cpp_redis;

ll fatorial(ll n, client &client) {
	auto fat = client.get(to_string(n));
	client.sync_commit();

	auto as_str = fat.get();

	if(as_str.is_string()) {
		cout << "Esse fatorial, " << n <<"!, foi recuperado do banco " << endl;
		size_t sz = 0;
		return stoll(as_str.as_string(), &sz, 10);
	}

	if(n == 2 || n == 1) {
		cout << "Esse fatorial, " << n <<"!, foi calculado" << endl;
		return n;
	}

	ll fat_r = n*fatorial(n-1, client);
	cout << "Esse fatorial, " << n <<"!, foi calculado" << endl;
	auto set = client.set(to_string(n), to_string(fat_r));
	client.sync_commit();

	return fat_r;
}

int main(int argc, char *argv[]) {
	if(argc < 2) {
		cout << "Erro: nenhum valor informado.\nExemplo:\n\t$ ./atividade_redis 3\n\t$ Esse fatorial, 3!, foi calculado\n\t$ 6" << endl;
		return 0;
	}

	int valor = stoi(argv[1]);
	client client;
	client.connect("127.0.0.1", 6379, 
			[](const string &host, size_t port, connect_state status) {
				if(status == connect_state::dropped) {
					cout << "client disconnected from "  << host << ":" << port << endl;
				}
			});

	ll fat = fatorial(valor, client);
	cout << valor << "! = " << fat << endl;

	return 0;
}
