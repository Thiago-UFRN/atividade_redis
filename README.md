# Atividade Redis -- IMD0094

Primeiro instale a bilbioteca cpp_redis

```bash
sudo ./install_cpp_redis
```
Agora compile o arquivo atividade_redis.cpp

```bash
make
```

Agora execute o programa atividade_redis, passando como parâmetro o número que você deseja calcular o fatorial

```bash
./atividade_redis 4
```

Note que a primeira vez que você executar esse comando todos os fatoriais 3!, 4! (2! é sempre calculado) serão armazenados no banco. Da próxima vez que você executar o programa passando 4 como parâmetro, o valor não será calculado, apenas recuperado do banco. Valores maiores que 4! serão calculados até encontrarem um valor no banco, por exemplo, se 6! fosse requerido então o algoritmo iria calcular 5! e quando chegasse em 4! iria apenas recuperar o valor do banco e encerrar o cálculo.
