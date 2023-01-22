#if !defined(LASAGNA_MASTER_H_)
#define LASAGNA_MASTER_H_

/*  IMPORTANT:
    To solve this exercise you do not need to edit 
    the contents of this file.
*/


namespace lasagna_master {
    class lasagna {
        public:
            static int ovenTime();
            static int preparationTime(int numberOfLayers);
            static int remainingOvenTime(int actualMinutesInOven);
            static int elapsedTime(int numberOfLayers, int actualMinutesInOven);
    };

} // namespace lasagna_master

#endif
