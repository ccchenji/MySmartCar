#include  "include.h"
#include  "datamap.h"

//union cnf_union {     //定义联合体 储存浮点数
//	float f;
//	uint32 i;
//};
struct datamap Config;
union cnf_union my_cnf[cnf_num];   

void load_config(void){

	uint16 i;

	for (i = 0; i < cnf_num;i++)
	{
		my_cnf[i].i = flash_read(PAGE_Config, i * 32, uint32);
	}
    //  my_cnf[2].i = flash_read(PAGE_Config, 0, uint32);
}

//Write current configuration
void Write_config(void){
	uint16 i;
 	flash_erase_sector(PAGE_Config); //Erase pages
        DELAY_MS(50);
	for(i=0;i<cnf_num;i++){
     flash_write(PAGE_Config, i*32, my_cnf[i].i);
     DELAY_MS(20);
	}
}




//if(Config.is_good != (int16_t)0xA55A){ //Data invalid, load default configuartion
//	Config.is_good = 0xA55A;
//	Config.dGx_offset = 0;
//	Config.dGy_offset = 0;
//	Config.dGz_offset = 0;
//
//	Config.dMx_offset = 0;
//	Config.dMy_offset = 0;
//	Config.dMz_offset = 0;
//
//	Write_config();	 //Write default configuration
//}