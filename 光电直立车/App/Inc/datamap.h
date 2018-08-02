#ifndef __DATAMAP_H
#define __DATAMAP_H
#define PAGE_Config   (FLASH_SECTOR_NUM-1)
#define cnf_num 40 
extern struct datamap Config;
extern union cnf_union my_cnf[cnf_num];    
struct datamap
{
	int16_t is_good;   //�����Ƿ���Ч
	int16_t dGx_offset;
	int16_t dGy_offset;
	int16_t dGz_offset;
	
	int16_t dMx_offset;
	int16_t dMy_offset;
	int16_t dMz_offset; // 7*2 Bytes
};
union cnf_union {     //���������� ���渡����
	float f;
	uint32 i;
};
void Write_config(void);
void load_config(void);
#endif