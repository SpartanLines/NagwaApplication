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
    public partial class CreateCase : UserControl
    {
        Controller ControllerObj;
        int ID;
        public CreateCase(int id)
        {
            InitializeComponent();
            ControllerObj = new Controller();
            DataTable dt = ControllerObj.GetReservNoCase(id);
            gridControl1.DataSource = dt;
            ID = id;

        }
        
        private void gridControl1_Click(object sender, EventArgs e)
        {

        }

        private void cardView1_DoubleClick(object sender, EventArgs e)
        {
            DataRow dr = cardView1.GetDataRow(this.cardView1.FocusedRowHandle);


        }
    }
}
