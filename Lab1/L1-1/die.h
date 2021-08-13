/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
'* Program name    :                                                   * 
'*                                                                     * 
'* Written by      : Bailey Nichols                                    * 
'*                                                                     * 
'* Purpose         : To cause a message to display on the system       * 
'*                   console. This program will be executed from the   * 
'*                   terminal at the computer room door by personnel   * 
'*                   needing service.                                  * 
'*                                                                     * 
'* Inputs          : User enters HELLO on the terminal command line    * 
'*                                                                     * 
'* Outputs         : Display of entery request on the system terminal  * 
'*                                                                     * 
'* Calls           : No internal or external calls                     * 
'*                                                                     * 
'* Structure       : BEGIN                                             * 
'*                        Straight line code no sub-processes          * 
'*                   STOP                                              * 
'*                        End of Program                               * 
'*                                                                     * 
'*---------------------------------------------------------------------* 
'* Change Log:                                                         * 
'*                         Revision                                    * 
'*       Date    Changed  Rel Ver Mod Purpose                          * 
'* 06/06/12      jurrutia 000.000.000 Initial release of program       * 
'*                                                                     * 
'* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
*/
class die {
private:
    int num; //value of the roll in this instance (1-6)
public:
    die();
    //default constuctor
    //init num to 1
    //---------------
    void roll();
    //Function to roll die
    //Function uses rand() genorator to get int 1-6 in private data member num
    //-------------------------
    void getNum(); const
    //function to retun top face of the die
    //returns "the value of the instance variable num"
};

