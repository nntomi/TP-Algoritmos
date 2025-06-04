#ifndef API_H_INCLUDED
#define API_H_INCLUDED

void verRanking();
size_t WriteCallback(void *contents, size_t , size_t nmemb, void *userp);
void guardarRanking(const char *codigoGrupo, const char *nombreJugador, int esGanador);
void resetearGrupo(const char *codigoGrupo);

#endif // API_H_INCLUDED

