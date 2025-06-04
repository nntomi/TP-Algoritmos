#include <curl/curl.h>
// Función que maneja la respuesta de la solicitud HTTP
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp)
{
    size_t realsize = size * nmemb;
    printf("%.*s", (int)realsize, (char *)contents);
    return realsize;
}

void verRanking() //GET.
{
    CURL *curl;
    CURLcode res;
// Inicializar el manejo de curl
    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();
    if (curl)
    {
// Establecer la URL de la solicitud GET
        curl_easy_setopt(curl, CURLOPT_URL, "https://algoritmos-api.azurewebsites.net/api/doce/limite");
        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "X-Secret: FADSFAS");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);
// Establecer la función de retorno de llamada para manejar la respuesta
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
// Realizar la solicitud HTTP GET
        res = curl_easy_perform(curl);

// Verificar si la solicitud fue exitosa
        if (res != CURLE_OK)
            fprintf(stderr, "Error en la solicitud: %s\n",
                    curl_easy_strerror(res));
// Limpiar y cerrar el manejo de curl
        curl_easy_cleanup(curl);
// Finalizar el manejo global de curl
        curl_global_cleanup();
    }

}

void guardarRanking(const char *codigoGrupo, const char *nombreJugador, int esGanador) //POST.
{
    CURL *curl;
    CURLcode res;

    char postData[512];
    snprintf(postData, sizeof(postData),
             "{ \"CodigoGrupo\": \"%s\", \"jugador\": { \"nombre\": \"%s\", \"vencedor\": %d } }",
             codigoGrupo, nombreJugador, esGanador);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_URL, "https://algoritmos-api.azurewebsites.net/api/doce");
        curl_easy_setopt(curl, CURLOPT_POSTFIELDS, postData);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);

        struct curl_slist *headers = NULL;
        headers = curl_slist_append(headers, "Content-Type: application/json");
        curl_easy_setopt(curl, CURLOPT_HTTPHEADER, headers);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
        {
            fprintf(stderr, "Error en POST: %s\n", curl_easy_strerror(res));
        }
        else
        {
            printf("Datos enviados correctamente.\n");
        }

        curl_slist_free_all(headers);
        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}
void resetearGrupo(const char *codigoGrupo) //DELETE.
{
    CURL *curl;
    CURLcode res;

    char url[256];
    snprintf(url, sizeof(url), "https://algoritmos-api.azurewebsites.net/api/doce/%s", codigoGrupo);

    curl_global_init(CURL_GLOBAL_DEFAULT);
    curl = curl_easy_init();

    if (curl)
    {
        curl_easy_setopt(curl, CURLOPT_CUSTOMREQUEST, "DELETE");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_SSL_VERIFYPEER, 0L);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);

        res = curl_easy_perform(curl);
        if (res != CURLE_OK)
        {
            fprintf(stderr, "Error al resetear grupo: %s\n", curl_easy_strerror(res));
        }
        else
        {
            printf("Grupo %s reseteado correctamente.\n", codigoGrupo);
        }

        curl_easy_cleanup(curl);
    }

    curl_global_cleanup();
}

