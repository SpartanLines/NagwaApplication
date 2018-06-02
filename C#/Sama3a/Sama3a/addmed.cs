using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Data;
using System.Drawing;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MyProject
{
    public partial class addmed : Form
    {
        Controller controllerObj;
        public addmed()
        {
            InitializeComponent();
            controllerObj = new Controller();
        }

        private void add_Click(object sender, EventArgs e)
        {
            if (mname.Text == "" || ed.Text == "" || qua.Text == "" )
            {
                MessageBox.Show("you must insert name,expiry date and quantity");
            }
            else
            {
                int g = controllerObj.getmaxm();
                g++;     
                hospital h = new hospital();
                int hid =h.getHID();

                int r = controllerObj.addmed(g,mname.Text.ToString(), desc.Text.ToString(), se.Text.ToString(), Convert.ToDateTime(ed.Text));
                if(r>0)
                {
                    int k = controllerObj.addmed1(g, hid, Convert.ToInt32(qua.Text));
                   
    
                    MessageBox.Show("medicine is added ");
                }
                else
                {
                    MessageBox.Show("Insertion Failed");
                }


            }
        }

        private void qua_TextChanged(object sender, EventArgs e)
        {

        }
    }
    }

