int hamming(unsigned char data){
  // Declaring variables
  unsigned char index;
  unsigned char hamming[12];
  int result = 0x00;

  // Initializing the array
  for (index = 0; index < 12; ++index){
    hamming[index] = 0x00;
  }

  hamming[11] =  (data)%2;
  hamming[10] =  (data>>1)%2;
  hamming[9]  =  (data>>2)%2;
  hamming[8]  =  (data>>3)%2;
  hamming[6]  =  (data>>4)%2;
  hamming[5]  =  (data>>5)%2;
  hamming[4]  =  (data>>6)%2;
  hamming[2]  =  (data>>7)%2;

  hamming[0] = hamming[2]^hamming[4]^hamming[6]^hamming[8]^hamming[10];
  hamming[1] = hamming[2]^hamming[5]^hamming[6]^hamming[9]^hamming[10];
  hamming[3] = hamming[4]^hamming[5]^hamming[6]^hamming[11];
  hamming[7] = hamming[8]^hamming[9]^hamming[10]^hamming[11];

  // Wrinting the result
  for (index = 0; index < 12; index++){
    result = ((result<<1) | hamming[index]);
  }

  return result;
}