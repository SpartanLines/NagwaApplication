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
    
    public partial class Reserve : Form
    {
        Controller controllerObj;
        public Reserve()
        {
            InitializeComponent();
            TimePicker.Format = DateTimePickerFormat.Time;
            TimePicker.ShowUpDown = true;
            controllerObj = new Controller();
          
        }

        private void Reserve_Load(object sender, EventArgs e)
        {
            reservation r = new reservation();
            int docID = r.getDocID();
            label1.Text = controllerObj.docFname(docID) + " " + controllerObj.docLname(docID);
            DataTable hosp = controllerObj.dochosp(docID);
            //DataSet hospital = new DataSet();
            //hospital.Tables.Add(hosp);
            hospitals.DataSource = hosp;
            hospitals.DisplayMember = "Name";
            fees.Text = Convert.ToString( controllerObj.getfees(docID));
            DataTable Ddays = controllerObj.docdays(docID, Convert.ToString(hospitals.Text));
            //DataSet DocDays = new DataSet();
            //DocDays.Tables.Add(Ddays);
            days.DataSource = Ddays;
            days.DisplayMember = "Day";

            DataTable Dhrs = controllerObj.dochours(docID, days.Text, hospitals.Text);
            StTime.Text = Dhrs.Rows[0][0].ToString()+ ":" + Dhrs.Rows[0][1].ToString();
            EndTime.Text = Dhrs.Rows[0][2].ToString() + ":" + Dhrs.Rows[0][3].ToString();





        }

        private void monthCalendar1_DateChanged(object sender, DateRangeEventArgs e)
        {
            
        }

        private void dateTimePicker1_ValueChanged(object sender, EventArgs e)
        {
             
               
        }

        private void dateTimePicker2_ValueChanged(object sender, EventArgs e)
        {
            
        }

        private void button1_Click(object sender, EventArgs e)
        {
            
            patientlogin p = new patientlogin();

            int PID = p.getPID();
            string theDate = datePicker.Value.ToString("yyyy-MM-dd");
            string time = TimePicker.Value.ToString("hh:mm");
            string day = datePicker.Value.DayOfWeek.ToString();
            int h =Convert.ToInt16( TimePicker.Value.ToString("hh"));
            int m = Convert.ToInt16(TimePicker.Value.ToString("mm"));
            reservation r = new reservation();
            int docID = r.getDocID();
            DataTable Ddays = controllerObj.docdays(docID, Convert.ToString(hospitals.Text));
            DataTable Dhrs = controllerObj.dochours(docID, days.Text, hospitals.Text);
            int c = Ddays.Rows.Count;
            bool inday=false;
            for (int i=0; i<c; i++)
            {
                if (day == Ddays.Rows[i][0].ToString())
                {
                    inday = true;
                    break;
                }
                
            }
            if (inday==false)
            {
                MessageBox.Show("Unavailable day");
            }
            else
            {
                if (h >= Convert.ToInt16(Dhrs.Rows[0][0]) && m >= Convert.ToInt16(Dhrs.Rows[0][1]) && h <= Convert.ToInt16(Dhrs.Rows[0][2]) )
                {
                    //MessageBox.Show("available slot");
                    int rno = controllerObj.Rnumber();
                    rno++;
                    int res = controllerObj.Reserve(rno, theDate, time,  PID, controllerObj.HospID(hospitals.Text), docID, controllerObj.getfees(docID));
                    if (res > 0)
                    {
                        MessageBox.Show("Reservation Successful");
                        patient_main main = new patient_main();
                        main.Show();
                        
                    }
                    else
                        MessageBox.Show("Sorry this time slot is already reserved");

                }
                else MessageBox.Show("chosen time not in doctor's working hours");

            }
            



           
        }

        private void hospitals_SelectedIndexChanged(object sender, EventArgs e)
        {
            reservation r = new reservation();
            int docID = r.getDocID();
            DataTable Ddays = controllerObj.docdays(docID, Convert.ToString(hospitals.Text));
            //DataSet DocDays = new DataSet();
            //DocDays.Tables.Add(Ddays);
            days.DataSource = Ddays;
            days.DisplayMember = "Day";
            //DataTable Dhrs = controllerObj.dochours(docID, days.Text, hospitals.Text);
            //StTime.Text = Dhrs.Rows[0][1].ToString() + ":" + Dhrs.Rows[0][2].ToString();
            //EndTime.Text = Dhrs.Rows[0][3].ToString() + ":" + Dhrs.Rows[0][4].ToString();
        }

        private void days_SelectedIndexChanged(object sender, EventArgs e)
        {
            reservation r = new reservation();
            int docID = r.getDocID();
            DataTable Dhrs = controllerObj.dochours(docID, days.Text, hospitals.Text);
            StTime.Text = Dhrs.Rows[0][0].ToString() + ":" + Dhrs.Rows[0][1].ToString();
            EndTime.Text = Dhrs.Rows[0][2].ToString() + ":" + Dhrs.Rows[0][3].ToString();
        }
    }
}
