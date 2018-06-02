using System;
using System.Collections.Generic;
using System.ComponentModel;
using System.Drawing;
using System.Data;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Windows.Forms;

namespace MyProject
{
   
    public partial class UserControl1 : UserControl
    {

        Controller ControllerObj;
        
        public UserControl1(int id)
        {
            InitializeComponent();
            ControllerObj = new Controller();
            DataTable dt=ControllerObj.GetanswerInfo(id);
            int count = dt.Rows.Count;
            label1.Text = dt.Rows[0][0].ToString();
            int bot = label1.Bottom+50;

            for(int i=0;i<count;i++)
            {
                Label l = new Label();
                l.Text = dt.Rows[i][1].ToString();
                l.Top = bot;
                
                bot = l.Bottom + 50;
                l.Show();

                this.Controls.Add((Label)l);
            }
            /*
            foreach(element in dt)
             * { label s=new label;
             * 
             *  Label l = new Label();
                l.Top = bot + 50 * i;
                l.Show();
              
                this.Controls.Add((Label)l);
             * 
             * 
             * 
             * }
             textbox1.top= bot+50;
             * 
             
             
             
             
             */
        }

    
        private void richTextBox1_TextChanged(object sender, EventArgs e)
        {

        }

        private void UserControl1_Load(object sender, EventArgs e)
        {
            int bot= label1.Bottom;
            for(int i=1;i<20;i++)
            {
                Label l=new Label();
                l.Top = bot + 50 * i;
                l.Show();
                l.Text="OMAE WA MOU SHINDERU";
               
            }
        }

        private void button2_Click(object sender, EventArgs e)
        {

        }
    }
}
