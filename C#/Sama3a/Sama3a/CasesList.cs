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
    public partial class CasesList : UserControl
    {
        Controller ControllerObj;
        int id;
        public CasesList(int id)
        {
            InitializeComponent();
            this.id = id;
        }

        private void CasesList_Load(object sender, EventArgs e)
        {
            ControllerObj = new Controller();
            DataTable dt = ControllerObj.GetMyCases(id);
            gridControl1.DataSource = dt;
           


        }
    }
}
