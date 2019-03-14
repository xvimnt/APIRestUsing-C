#include "practica1.h"

BinaryTree maestros;
CircularList cursos;
doubleLinkedList edificios;
arrayList dias;

static char encoding_table[] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H',
                                'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P',
                                'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X',
                                'Y', 'Z', 'a', 'b', 'c', 'd', 'e', 'f',
                                'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n',
                                'o', 'p', 'q', 'r', 's', 't', 'u', 'v',
                                'w', 'x', 'y', 'z', '0', '1', '2', '3',
                                '4', '5', '6', '7', '8', '9', '+', '/'};
static char *decoding_table = NULL;
static int mod_table[] = {0, 2, 1};

void build_decoding_table() {

  decoding_table = (char*) malloc(256);

  for (int i = 0; i < 64; i++)
    decoding_table[(unsigned char) encoding_table[i]] = i;
}

char *base64_encode(const unsigned char *data,
                    size_t input_length,
                    size_t *output_length) {

  *output_length = 4 * ((input_length + 2) / 3);

  char *encoded_data = (char*) malloc(*output_length);
  if (encoded_data == NULL) return NULL;

  unsigned int i , j;
  for (i = 0, j = 0; i < input_length;) {

    uint32_t octet_a = i < input_length ? (unsigned char)data[i++] : 0;
    uint32_t octet_b = i < input_length ? (unsigned char)data[i++] : 0;
    uint32_t octet_c = i < input_length ? (unsigned char)data[i++] : 0;

    uint32_t triple = (octet_a << 0x10) + (octet_b << 0x08) + octet_c;

    encoded_data[j++] = encoding_table[(triple >> 3 * 6) & 0x3F];
    encoded_data[j++] = encoding_table[(triple >> 2 * 6) & 0x3F];
    encoded_data[j++] = encoding_table[(triple >> 1 * 6) & 0x3F];
    encoded_data[j++] = encoding_table[(triple >> 0 * 6) & 0x3F];
  }

  for (int i = 0; i < mod_table[input_length % 3]; i++)
    encoded_data[*output_length - 1 - i] = '=';

  return encoded_data;
}


std::string ReadFile(const char *name)
{
  FILE *file;
  unsigned char *buffer;
  char *lobi;

  //Open file
  file = fopen(name , "rb");
  if (!file)
    {
      fprintf(stderr, "Unable to open file %s", name);
      return "error";
    }

  //Get file length
  fseek(file, 0, SEEK_END);
  long int fileLen=ftell(file);
  fseek(file, 0, SEEK_SET);

  //Allocate memory
  buffer=(unsigned char*)malloc(fileLen+1);
  if (!buffer)
    {
      fprintf(stderr, "Memory error!");
      fclose(file);
      return "error";
    }

  
  //Read file contents into buffer
  fread(buffer, fileLen, 1, file);
  size_t output_length = 0;
  lobi = base64_encode(buffer, fileLen, &output_length);

  return (std::string) lobi;

  //printf("%s\n", lobi);
  FILE *fp;
	fp = fopen ( "salida.txt", "w+" );
	//if (fp==NULL) {fputs ("File error",stderr); exit (1);}
	fputs(lobi,fp);
	fclose ( fp );

  fclose(file);
  //insert_blob(buffer);
  free(buffer);
}

std::string practica1::getB64(const std::string& img)
{
        if(img == "matrix"){
                return ReadFile("/home/xvimnt/practica1/practica1/src/imageBef.png");
        }
        return "opcion invalida";
}

std::string practica1::newProfessor(const Data& data){
        maestros.add(data);
        return "ok";
}

std::string practica1::newCourse(const Data& data){
        cursos.add(data);
        return "ok";
}

std::string practica1::newBuilding(const deuxData& data){
  edificios.add(data);
  return "ok";
}

std::string practica1::getGraphic( const std::string& choice)
{
    if(choice == "arbol")
    {
      return maestros.getGraphic();
    }else if(choice == "cursos"){
      return cursos.getGraphic();
    }else if(choice == "edificios"){
      return  edificios.getGraphic();
    }else if(choice == "dias"){
      return dias.getGraphic();
    }
    return "opcion invalida";
}

std::string practica1::newDay(const std::string& choice){
  deuxData day = new deuxData();
  
  dias.add(day);
  return "ok";
}