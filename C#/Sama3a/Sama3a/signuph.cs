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
    public partial class signuph : Form

    {
        Controller controllerObj;
         
        public signuph()
        {
            InitializeComponent();
            controllerObj = new Controller();
            city.Items.Add("Zamalek");
            city.Items.Add("Maadi");
            city.Items.Add("Mohandessin");
            city.Items.Add("Agouza");
            city.Items.Add("Nasr City");
            city.Items.Add("Sheikh Zayed");
            city.Items.Add("Al Haram");
            city.Items.Add("6 of October");
            

        }
        //static int ID;
        //public void setid(int id)
        //{
          //  ID = id;
        //}
       // public int getid()
        //{
          //  return ID;
        //}
        private void sign_Click(object sender, EventArgs e)
        {
            if (Username.Text == "" || Password.Text == "" || name.Text == "" )
            {
                MessageBox.Show("you must insert username,password and name ");
            }
            else
            {
                int g = controllerObj.getmaxh();
                g++;
                int r = controllerObj.inserth(g,name.Text.ToString(),Convert.ToInt32(no.Text),addr.Text.ToString(), city.Text.ToString() );
                if (r > 0)
                {
                    int p = controllerObj.InsertUserh1(Username.Text.ToString(), Password.Text.ToString(),g);
                    
                    MessageBox.Show("thank you for signingup");
                
                    menuh a = new menuh();
                    a.Show();
                }
                else
                {
                    MessageBox.Show("Insertion Failed");
                }


            }
        }

        private void addr_TextChanged(object sender, EventArgs e)
        {

        }

        private void name_TextChanged(object sender, EventArgs e)
        {

        }

        private void Username_TextChanged(object sender, EventArgs e)
        {

        }

        private void no_TextChanged(object sender, EventArgs e)
        {

        }
    }
}
