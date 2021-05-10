// original
// for (y)
//     for (jCprime)
//         for (jSprime)
//             B1_Blocal_r1_r_props_init( jCprime, jSprime )
//             B1_Blocal_r1_i_props_init( jCprime, jSprime )
//             B1_Bfirst_r1_r_props_init( jCprime, jSprime )
//             B1_Bfirst_r1_i_props_init( jCprime, jSprime )
//             B1_Bsecond_r1_r_props_init( jCprime, jSprime )
//             B1_Bsecond_r1_i_props_init( jCprime, jSprime )
//             B1_Bthird_r1_r_props_init( jCprime, jSprime )
//             B1_Bthird_r1_i_props_init( jCprime, jSprime )
//     for (wnumBlock)
//         B1_Blocal_r1_r_diquark() // like a tmp variable
//         B1_Blocal_r1_i_diquark()
//         B1_Bfirst_r1_r_diquark()
//         B1_Bfirst_r1_i_diquark()
//         B1_Bthird_r1_r_diquark()
//         B1_Bthird_r1_i_diquark()
//         for (jCprime)
//             for (jSprime)
//                 B1_Blocal_r1_r_props( jCprime, jSprime )
//                 B1_Blocal_r1_i_props( jCprime, jSprime )
//                 B1_Bfirst_r1_r_props( jCprime, jSprime )
//                 B1_Bfirst_r1_i_props( jCprime, jSprime )
//                 B1_Bsecond_r1_r_props( jCprime, jSprime )
//                 B1_Bsecond_r1_i_props( jCprime, jSprime )
//                 B1_Bthird_r1_r_props( jCprime, jSprime )
//                 B1_Bthird_r1_i_props( jCprime, jSprime )
//     for (jCprime)
//         for (jSprime)
//             for (m)
//                 B1_Blocal_r1_r_update( jCprime, jSprime, m )
//                 B1_Blocal_r1_i_update( jCprime, jSprime, m )
//                 B1_Bfirst_r1_r_update( jCprime, jSprime, m )
//                 B1_Bfirst_r1_i_update( jCprime, jSprime, m )
//                 B1_Bsecond_r1_r_update( jCprime, jSprime, m )
//                 B1_Bsecond_r1_i_update( jCprime, jSprime, m )
//                 B1_Bthird_r1_r_update( jCprime, jSprime, m )
//                 B1_Bthird_r1_i_update( jCprime, jSprime, m )
//                 flip_B1_Blocal_r1_r_update( jCprime, jSprime, m )
//                 flip_B1_Blocal_r1_i_update( jCprime, jSprime, m )
//                 flip_B1_Bfirst_r1_r_update( jCprime, jSprime, m )
//                 flip_B1_Bfirst_r1_i_update( jCprime, jSprime, m )
//                 flip_B1_Bsecond_r1_r_update( jCprime, jSprime, m )
//                 flip_B1_Bsecond_r1_i_update( jCprime, jSprime, m )
//                 flip_B1_Bthird_r1_r_update( jCprime, jSprime, m )
//                 flip_B1_Bthird_r1_i_update( jCprime, jSprime, m )


for (y)
    for (jCprime)
        for (jSprime)
            B1_Blocal_r1_r_props_init( jCprime, jSprime )
            B1_Blocal_r1_i_props_init( jCprime, jSprime )
            B1_Bfirst_r1_r_props_init( jCprime, jSprime )
            B1_Bfirst_r1_i_props_init( jCprime, jSprime )
            B1_Bsecond_r1_r_props_init( jCprime, jSprime )
            B1_Bsecond_r1_i_props_init( jCprime, jSprime )
            B1_Bthird_r1_r_props_init( jCprime, jSprime )
            B1_Bthird_r1_i_props_init( jCprime, jSprime )

    for (wnumBlock)
        B1_Blocal_r1_r_diquark() : buf_B1_Blocal_diquark_r1_r[ 0 ]
        B1_Blocal_r1_i_diquark() : buf_B1_Blocal_diquark_r1_i[ 0 ]
        B1_Bfirst_r1_r_diquark() : buf_B1_Bfirst_diquark_r1_r[ 0 ]
        B1_Bfirst_r1_i_diquark() : buf_B1_Bfirst_diquark_r1_i[ 0 ]
        B1_Bthird_r1_r_diquark() : buf_B1_Bthird_diquark_r1_r[ 0 ]
        B1_Bthird_r1_i_diquark() : buf_B1_Bthird_diquark_r1_i[ 0 ]
        for (jCprime)
            for (jSprime)
                B1_Blocal_r1_r_props( jCprime, jSprime ) : buf_B1_Blocal_props_r1_r[ jCprime, jSprime ]
                B1_Blocal_r1_i_props( jCprime, jSprime ) : buf_B1_Blocal_props_r1_i[ jCprime, jSprime ]
                B1_Bfirst_r1_r_props( jCprime, jSprime ) : buf_B1_Bfirst_props_r1_r[ jCprime, jSprime ]
                B1_Bfirst_r1_i_props( jCprime, jSprime ) : buf_B1_Bfirst_props_r1_i[ jCprime, jSprime ]
                B1_Bsecond_r1_r_props( jCprime, jSprime ) : buf_B1_Bsecond_props_r1_r[ jCprime, jSprime ]
                B1_Bsecond_r1_i_props( jCprime, jSprime ) : buf_B1_Bsecond_props_r1_i[ jCprime, jSprime ]
                B1_Bthird_r1_r_props( jCprime, jSprime ) : buf_B1_Bthird_props_r1_r[ jCprime, jSprime ]
                B1_Bthird_r1_i_props( jCprime, jSprime ) : buf_B1_Bthird_props_r1_i[ jCprime, jSprime ]
    for (jCprime)
        for (jSprime)
            for (m)
                B1_Blocal_r1_r_update( jCprime, jSprime, m ) : buf_B1_Blocal_r1_r[ jCprime, jSprime, m ]
                B1_Blocal_r1_i_update( jCprime, jSprime, m ) : buf_B1_Blocal_r1_i[ jCprime, jSprime, m ]
                B1_Bfirst_r1_r_update( jCprime, jSprime, m ) : buf_B1_Bfirst_r1_r[ jCprime, jSprime, m ]
                B1_Bfirst_r1_i_update( jCprime, jSprime, m ) : buf_B1_Bfirst_r1_i[ jCprime, jSprime, m ]
                B1_Bsecond_r1_r_update( jCprime, jSprime, m ) : buf_B1_Bsecond_r1_r[ jCprime, jSprime, m ]
                B1_Bsecond_r1_i_update( jCprime, jSprime, m ) : buf_B1_Bsecond_r1_i[ jCprime, jSprime, m ]
                B1_Bthird_r1_r_update( jCprime, jSprime, m ) : buf_B1_Bthird_r1_r[ jCprime, jSprime, m ]
                B1_Bthird_r1_i_update( jCprime, jSprime, m ) : buf_B1_Bthird_r1_i[ jCprime, jSprime, m ]
                flip_B1_Blocal_r1_r_update( jCprime, jSprime, m ) : buf_flip_B1_Blocal_r1_r[ jCprime, jSprime, m ]
                flip_B1_Blocal_r1_i_update( jCprime, jSprime, m ) : buf_flip_B1_Blocal_r1_i[ jCprime, jSprime, m ]
                flip_B1_Bfirst_r1_r_update( jCprime, jSprime, m ) : buf_flip_B1_Bfirst_r1_r[ jCprime, jSprime, m ]
                flip_B1_Bfirst_r1_i_update( jCprime, jSprime, m ) : buf_flip_B1_Bfirst_r1_i[ jCprime, jSprime, m ]
                flip_B1_Bsecond_r1_r_update( jCprime, jSprime, m ) : buf_flip_B1_Bsecond_r1_r[ jCprime, jSprime, m ]
                flip_B1_Bsecond_r1_i_update( jCprime, jSprime, m ) : buf_flip_B1_Bsecond_r1_i[ jCprime, jSprime, m ]
                flip_B1_Bthird_r1_r_update( jCprime, jSprime, m ) : buf_flip_B1_Bthird_r1_r[ jCprime, jSprime, m ]
                flip_B1_Bthird_r1_i_update( jCprime, jSprime, m ) : buf_flip_B1_Bthird_r1_i[ jCprime, jSprime, m ]
