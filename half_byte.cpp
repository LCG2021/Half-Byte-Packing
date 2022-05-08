void compress(unsigned char* in, size_t input_length)
{
    unsigned int* inUInt = reinterpret_cast<unsigned int*>(in);
    unsigned long long* inULong = reinterpret_cast<unsigned long long*>(in);

    for(size_t i = 0; i < input_length / 8; ++i) 
    {
        unsigned long long value = inULong[i] & 0xF0F0F0F0F0F0F0F0;
        value = (value >> 4) | (value << 8);
        value &= 0xFF00FF00FF00FF00;
        value |= (value << 8);
        value &= 0xFFFF0000FFFF0000;
        value |= (value << 16);
        inUInt[i] = static_cast<unsigned int>(value >> 32);
    }
}
