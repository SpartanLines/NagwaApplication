using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Data;
using System.Windows.Forms;


namespace MyProject
{
    public class Controller
    {
        DBManager dbMan;
        public Controller()
        {
            dbMan = new DBManager();
        }

     public DataTable QuestionList(string method,string second)
        {
         string storedprocedurename="";
         Dictionary<string, object> Parameters = new Dictionary<string, object>();
         if (method == "Keyword")
         {
             storedprocedurename = StoredProcedures.SearchQuestionKey;
             Parameters.Add("Keyword", second);
         }
         else
         {
             storedprocedurename = StoredProcedures.SearchQuestionSpec;
             Parameters.Add("Speciality", second);
         }
           
            //Parameters.Add("@Pname", Pname);
         return dbMan.ExecuteReader(storedprocedurename, Parameters);
        }
     public DataTable GetanswerInfo(int id)
     {
         Dictionary<string, object> Parameters = new Dictionary<string, object>();
         Parameters.Add("@Qid", id);
         string procname = StoredProcedures.AnswerInfo;
         return dbMan.ExecuteReader(procname, Parameters);
         
     }
        public DataTable GetReservNoCase(int id)
        {
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@doctorid", id);
            string procname = StoredProcedures.Createnewcase;
            return dbMan.ExecuteReader(procname, Parameters);
        }
        public DataTable DrLogin(string username, string password)
        {

            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@Username", username);
            Parameters.Add("@Password", password);
            string procname = StoredProcedures.DrLogin;
            return dbMan.ExecuteReader(procname, Parameters);
        }
        public DataTable DonorLogin(string username, string password)
        {

            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@Username", username);
            Parameters.Add("@Password", password);
            string procname = StoredProcedures.DonorLogin;
            return dbMan.ExecuteReader(procname, Parameters);
        }
        public DataTable GetName(int id)
     {
         Dictionary<string, object> Parameters = new Dictionary<string, object>();
         Parameters.Add("@id", id);
         string procname = StoredProcedures.MyName;
         return dbMan.ExecuteReader(procname, Parameters);

     }
        public int InsertAnswer(int DocID, string answer, int QID)
        {
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@DocID", DocID);
            Parameters.Add("@Answer", answer);
            Parameters.Add("@QID", QID);
            string procname = StoredProcedures.InsertAnswer;
            return dbMan.ExecuteNonQuery(procname, Parameters);
        }

        public DataTable TodayReserv(int id)
        {
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@id", id);
            string procname = StoredProcedures.TodayReserv;
            return dbMan.ExecuteReader(procname, Parameters);
        }
     
        public DataTable TodayReserv(int docid,int patid)
        {
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@doctorid", docid);
            Parameters.Add("Patientid", patid);
            string procname = StoredProcedures.TodayReserv;
            return dbMan.ExecuteReader(procname, Parameters);
        }


        public int InsertCase(int DocID, int PatientID, int urgency, string treatment, string operation,int amoundneeded)
        {
           // DateTime d =DateTime.Today;
          // string date= d.ToString("yyyy-mm-dd");
            
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            //Parameters.Add("@data", date);
            Parameters.Add("@doctorid", DocID);
            Parameters.Add("@patientid", PatientID);
            Parameters.Add("@urgency", urgency);
            Parameters.Add("@treatment", treatment);
            Parameters.Add("@operation", operation);
            Parameters.Add("@amoundneeded", amoundneeded);
            string procname = StoredProcedures.InsertNewCase;
            return dbMan.ExecuteNonQuery(procname, Parameters);
        }

        public DataTable Dashboardload(int id)
        {
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@doctorid", id);
            string procname = StoredProcedures.TodayReserv;
            return dbMan.ExecuteReader(procname, Parameters);
        }
        
        public DataTable GetMyCases(int id)
     {
         Dictionary<string, object> Parameters = new Dictionary<string, object>();
         Parameters.Add("@id", id);
         string procname = StoredProcedures.GetMyCases;
         return dbMan.ExecuteReader(procname, Parameters);

     }
        public DataTable ViewCases()
        {

            string procname = StoredProcedures.ViewAllCases;
            return dbMan.ExecuteReader(procname, null);
        }
        public int getmaxd()
        {
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            string procname = StoredProcedures.getmaxd;
            return (int)dbMan.ExecuteScalar(procname, Parameters);
        }

        public DataTable ViewDonations(int did)
        {
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            string procname = StoredProcedures.ViewDonations;
            Parameters.Add("@did", did);
            return dbMan.ExecuteReader(procname, Parameters);
        }
        public DataTable GetDoctors()
        {

            string procname = StoredProcedures.GetDoctors;
            return dbMan.ExecuteReader(procname, null);
        }
        public DataTable GetPatients()
        {

            string procname = StoredProcedures.GetPatients;
            return dbMan.ExecuteReader(procname, null);
        }
        public DataTable GetDonors()
        {

            string procname = StoredProcedures.GetDonors;
            return dbMan.ExecuteReader(procname, null);
        }

        public int DeleteDocUser(int id)
        {
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@id", id);
            string procname = StoredProcedures.DeleteDocUser;
            return dbMan.ExecuteNonQuery(procname, Parameters);
        }

        public int DeleteDonUser(int id)
        {
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@id4", id);
            string procname = StoredProcedures.DeleteDonUser;
            return dbMan.ExecuteNonQuery(procname, Parameters);
        }

        public int DeletePUser(int id)
        {
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@id3", id);
            string procname = StoredProcedures.DeletePUser;
            return dbMan.ExecuteNonQuery(procname, Parameters);
        }
        public int AdminInsert(string UserName, string password, string AdminID)
        {

            string StoredProcedureName = StoredProcedures.AdminInsert;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@UserName", UserName);
            Parameters.Add("@password", password);
            Parameters.Add("@AdminID", AdminID);
            return dbMan.ExecuteNonQuery(StoredProcedureName, Parameters);
        }
        public int AdminLogin(string UserName, string password)
        {

            string StoredProcedureName = StoredProcedures.AdminLogin;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@UserName", UserName);
            Parameters.Add("@Password", password);
            return dbMan.ExecuteNonQuery(StoredProcedureName, Parameters);
        }
        public int InsertDonation(int DonorID, int DonNo, int Amount, string DDate, int PID)
        {

            string StoredProcedureName = StoredProcedures.InsertDonation;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@DonorID", DonorID);
            Parameters.Add("@DonNo", DonNo);
            Parameters.Add("@Amount", Amount);
            Parameters.Add("@DDate", DDate);
            Parameters.Add("@PID", PID);
            return dbMan.ExecuteNonQuery(StoredProcedureName, Parameters);
        }
        public int Plogin(string username, string password)
        {

            string StoredProcedureName = StoredProcedures.PatientLogin;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@Username", username);
            Parameters.Add("@Password", password);

            if (dbMan.ExecuteScalar(StoredProcedureName, Parameters) == null)
                return 0;
            else
                return (int)dbMan.ExecuteScalar(StoredProcedureName, Parameters);
        }

        public DataTable Preservations(int PID)
        {
            string StoredProcedureName = StoredProcedures.Preservation;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@PID", PID);
            return dbMan.ExecuteReader(StoredProcedureName, Parameters);
        }
        public string Pname(int PID)
        {
            string StoredProcedureName = StoredProcedures.GetPname;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@PID", PID);
            return (string)dbMan.ExecuteScalar(StoredProcedureName, Parameters);
        }
        public int Addquestion(int QID, int PID, string category, DateTime Qdate, int Hr, int Mn, string Qcontent)
        {

            string StoredProcedureName = StoredProcedures.NewQuestion;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@QID", QID);
            Parameters.Add("@PID", PID);
            Parameters.Add("@Category", category);
            Parameters.Add("@Qdate", Qdate);
            Parameters.Add("@Hr", Hr);
            Parameters.Add("@min", Mn);
            Parameters.Add("@Qcontent", Qcontent);
            return dbMan.ExecuteNonQuery(StoredProcedureName, Parameters);


        }
        public DataTable QuestionsinCateg()
        {
            string storedproc = StoredProcedures.QuestionsinCat;
            return dbMan.ExecuteReader(storedproc, null);
        }
        public DataTable PatientInfo(int PID)
        {
            string StoredProcedureName = StoredProcedures.getPinfo;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@PID", PID);
            return dbMan.ExecuteReader(StoredProcedureName, Parameters);
        }
        public string GetPassword(int PID)
        {
            string StoredProcedureName = StoredProcedures.PatientPassword;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@PID", PID);
            return (string)dbMan.ExecuteScalar(StoredProcedureName, Parameters);
        }
        public int UpdatetPatient(int ID, string f, string m, string l, DateTime bdate, string addr, string occp, int phone, int age)
        {

            string StoredProcedureName = StoredProcedures.UpdatePinfo;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@PID", ID);
            Parameters.Add("@PFname", f);
            Parameters.Add("@PMname", m);
            Parameters.Add("@Plname", l);
            Parameters.Add("@Pbdate", bdate);
            Parameters.Add("@Paddress", addr);
            Parameters.Add("@Poccupation", occp);
            Parameters.Add("@Pphoneno", phone);
            Parameters.Add("@Page ", age);
            return dbMan.ExecuteNonQuery(StoredProcedureName, Parameters);
        }
        public int UpdatePPassword(int PID, string newpassword)
        {

            string StoredProcedureName = StoredProcedures.UpdatePassword;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@PID", PID);
            Parameters.Add("@Password", newpassword);


            return dbMan.ExecuteNonQuery(StoredProcedureName, Parameters);
        }
        public int InsertPatient(int ID, string f, string m, string l, DateTime bdate, string addr, string gender, string occp, int phone, int age)
        {

            string StoredProcedureName = StoredProcedures.InsertPatient;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@PID", ID);
            Parameters.Add("@PFname", f);
            Parameters.Add("@PMname", m);
            Parameters.Add("@Plname", l);
            Parameters.Add("@Pbdate", bdate);
            Parameters.Add("@Paddress", addr);
            Parameters.Add("@Pgender", gender);
            Parameters.Add("@Poccupation", occp);
            Parameters.Add("@Pphoneno", phone);
            Parameters.Add("@Page ", age);
            return dbMan.ExecuteNonQuery(StoredProcedureName, Parameters);
        }

        public int InsertUser(string un, string pw, int ID)
        {

            string StoredProcedureName = StoredProcedures.InsertUser;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@Puname", un);
            Parameters.Add("@Ppass", pw);
            Parameters.Add("@ID", ID);

            return dbMan.ExecuteNonQuery(StoredProcedureName, Parameters);
        }



        public DataTable searchhosploc(string location)
        {
            String StoredProcedureName = StoredProcedures.searchhosploc;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@location", location);
            return dbMan.ExecuteReader(StoredProcedureName, Parameters);
        }

        public DataTable docloc(string speciality, string location)
        {
            String StoredProcedureName = StoredProcedures.docloc;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@Dspec", speciality);
            Parameters.Add("@Hloc", location);
            return dbMan.ExecuteReader(StoredProcedureName, Parameters);
        }
        public DataTable docs(string speciality, int fees)
        {
            String StoredProcedureName = StoredProcedures.docs;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@Dspec", speciality);
            Parameters.Add("@fees", fees);
            return dbMan.ExecuteReader(StoredProcedureName, Parameters);
        }
        public DataTable docspec(string speciality)
        {
            String StoredProcedureName = StoredProcedures.docspec;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@Dspec", speciality);
            return dbMan.ExecuteReader(StoredProcedureName, Parameters);
        }
        // public DataTable doclsf(string speciality, string location,int fees)
        // {
        //   String StoredProcedureName = StoredProcedures.doclsf;
        // Dictionary<string, object> Parameters = new Dictionary<string, object>();
        // Parameters.Add("@Dspec", speciality);
        //Parameters.Add("@loc", location);
        //Parameters.Add("@fees", fees);
        //return dbMan.ExecuteReader(StoredProcedureName, Parameters);
        //}


        public DataTable searchqcat(string categ)
        {
            String StoredProcedureName = StoredProcedures.searchqcat;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@categ", categ);

            return dbMan.ExecuteReader(StoredProcedureName, Parameters);
        }

        public DataTable searchqueskc(string key, string categ)
        {
            String StoredProcedureName = StoredProcedures.searchqueskc;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@key", key);
            Parameters.Add("@categ", categ);
            return dbMan.ExecuteReader(StoredProcedureName, Parameters);
        }

        public DataTable searchqkey(string key)
        {
            String StoredProcedureName = StoredProcedures.searchqkey;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@key", key);
            return dbMan.ExecuteReader(StoredProcedureName, Parameters);
        }




        public DataTable searchmed(string name)
        {
            String StoredProcedureName = StoredProcedures.searchmed;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@name", name);
            return dbMan.ExecuteReader(StoredProcedureName, Parameters);
        }

        public DataTable hname(string name)
        {
            String StoredProcedureName = StoredProcedures.hname;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@name", name);
            return dbMan.ExecuteReader(StoredProcedureName, Parameters);
        }

        public string docFname(int docID)
        {
            String StoredProcedureName = StoredProcedures.docFname;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@docID", docID);
            return (string)dbMan.ExecuteScalar(StoredProcedureName, Parameters);

        }
        public string docLname(int docID)
        {
            String StoredProcedureName = StoredProcedures.docLname;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@docID", docID);
            return (string)dbMan.ExecuteScalar(StoredProcedureName, Parameters);

        }
        public int docID(string Fname, string Lname)
        {
            String StoredProcedureName = StoredProcedures.docID;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@Fname", Fname);
            Parameters.Add("@Lname", Lname);
            return (int)dbMan.ExecuteScalar(StoredProcedureName, Parameters);

        }
        public DataTable dochosp(int docID)
        {
            String StoredProcedureName = StoredProcedures.dochosp;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@docID", docID);
            return dbMan.ExecuteReader(StoredProcedureName, Parameters);
        }
        public int getfees(int ID)
        {
            String StoredProcedureName = StoredProcedures.docfees;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@docID", ID);

            return (int)dbMan.ExecuteScalar(StoredProcedureName, Parameters);

        }
        public DataTable docdays(int docID, string hospname)
        {
            String StoredProcedureName = StoredProcedures.docdays;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@docID", docID);
            Parameters.Add("@hospName", hospname);
            return dbMan.ExecuteReader(StoredProcedureName, Parameters);
        }
        public DataTable dochours(int docID, string day, string hospname)
        {
            String StoredProcedureName = StoredProcedures.dochrs;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@docID", docID);
            Parameters.Add("@hospName", hospname);
            Parameters.Add("@Day", day);
            return dbMan.ExecuteReader(StoredProcedureName, Parameters);
        }
        public int Reserve(int Rno, string RDate, string clock, int pid, int hid, int docID, int fees)
        {

            string StoredProcedureName = StoredProcedures.Reserve;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@Rno", Rno);
            Parameters.Add("@RDate", RDate);
            Parameters.Add("@clock", clock);
            Parameters.Add("@pid", pid);
            Parameters.Add("@hid", hid);
            Parameters.Add("@docID", docID);
            Parameters.Add("@fees", fees);

            return dbMan.ExecuteNonQuery(StoredProcedureName, Parameters);
        }
        public int Rnumber()
        {

            string StoredProcedureName = StoredProcedures.Rnumber;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();


            return (int)dbMan.ExecuteScalar(StoredProcedureName, Parameters);
        }
        public int HospID(string name)
        {

            string StoredProcedureName = StoredProcedures.HospID;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@Name", name);

            return (int)dbMan.ExecuteScalar(StoredProcedureName, Parameters);
        }
        public int inserth(int id, string n, int no, string add, string city)
        {

            string StoredProcedureName = StoredProcedures.inserth;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@ID", id);
            Parameters.Add("@hname", n);
            Parameters.Add("@hno", no);
            Parameters.Add("@haddress", add);
            Parameters.Add("@city", city);

            return dbMan.ExecuteNonQuery(StoredProcedureName, Parameters);
        }

        public int InsertUserh1(string un, string pw, int id)
        {

            string StoredProcedureName = StoredProcedures.InsertUserh1;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@n", un);
            Parameters.Add("@p", pw);
            Parameters.Add("@I", id);

            return dbMan.ExecuteNonQuery(StoredProcedureName, Parameters);
        }


        public int loginh(string username, string password)
        {

            string StoredProcedureName = StoredProcedures.loginh;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@Username", username);
            Parameters.Add("@Password", password);

            if (dbMan.ExecuteScalar(StoredProcedureName, Parameters) == null)
                return 0;
            else
                return (int)dbMan.ExecuteScalar(StoredProcedureName, Parameters);

        }

        public int getmaxh()
        {

            string StoredProcedureName = StoredProcedures.getmaxh;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();

            return (int)dbMan.ExecuteScalar(StoredProcedureName, Parameters);
        }

        public int getmaxp()
        {

            string StoredProcedureName = StoredProcedures.getmaxp;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();

            return (int)dbMan.ExecuteScalar(StoredProcedureName, Parameters);
        }
        public int getmaxm()
        {

            string StoredProcedureName = StoredProcedures.getmaxm;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();

            return (int)dbMan.ExecuteScalar(StoredProcedureName, Parameters);
        }

        public int addmed(int ID, string name, string des, string sideeff, DateTime exp)
        {

            string StoredProcedureName = StoredProcedures.addmed;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@ID", ID);
            Parameters.Add("@name", name);
            Parameters.Add("@des", des);
            Parameters.Add("@sideeff", sideeff);
            Parameters.Add("@exdate", exp);

            return dbMan.ExecuteNonQuery(StoredProcedureName, Parameters);
        }

        public int addmed1(int i, int hid, int quan)
        {

            string StoredProcedureName = StoredProcedures.addmed1;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@ID", i);
            Parameters.Add("@hid", hid);
            Parameters.Add("@quant", quan);

            return dbMan.ExecuteNonQuery(StoredProcedureName, Parameters);
        }

        public DataTable getdoc(int h)
        {
            String StoredProcedureName = StoredProcedures.getdoc;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@HID", h);
            return dbMan.ExecuteReader(StoredProcedureName, Parameters);
        }


        public int InsertNewDoc(string firstname, string minit, string lname, string speciality, string title, string gender, int phone)
        {
            string procname = StoredProcedures.InsertNewDoc;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@Fname", firstname);
            Parameters.Add("@Lname", lname);
            Parameters.Add("@Minit", minit);
            Parameters.Add("@Title", title);
            Parameters.Add("@Speciality", speciality);
            Parameters.Add("@gender", gender);
            Parameters.Add("@Phoneno", phone);

            return dbMan.ExecuteNonQuery(procname, Parameters);
        }

        public int InsertDocUser(string username, string pass, int id)
        {
            string proc = StoredProcedures.InsertAccount;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@username", username);
            Parameters.Add("@password", pass);
            Parameters.Add("@id", id);
            return dbMan.ExecuteNonQuery(proc, Parameters);
        }
        public DataTable fetchid(int phone)
        {
            string proc = StoredProcedures.fetchid;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@phoneno", phone);
            return dbMan.ExecuteReader(proc, Parameters);
        }
        public DataTable CheckDocuser(string name)
        {
            string proc = StoredProcedures.checkusername;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@username", name);
            return dbMan.ExecuteReader(proc, Parameters);

        }
        public int Insertwh(int ID, int i, string day, int sh, int sm, int eh, int em)
        {
            string StoredProcedureName = StoredProcedures.Insertwh;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@dID", ID);
            Parameters.Add("@hID", i);
            Parameters.Add("@Day", day);
            Parameters.Add("@sh", sh);
            Parameters.Add("@sm", sm);
            Parameters.Add("@endh", eh);
            Parameters.Add("@endm", em);
            return dbMan.ExecuteNonQuery(StoredProcedureName, Parameters);
        }
        public DataTable disp()
        {
            String StoredProcedureName = StoredProcedures.disp;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            return dbMan.ExecuteReader(StoredProcedureName, Parameters);
        }

        public void TerminateConnection()
        {
            dbMan.CloseConnection();
        }
    }
}
     /*   public DataTable SelectAllEmp()
        {

            string StoredProcedureName = StoredProcedures.SelectAllEmployees;
            return dbMan.ExecuteReader(StoredProcedureName, null);
        }


        public int InsertProject(string Pname, int pnumber, string Plocation, int Dnum)
        {

            string StoredProcedureName = StoredProcedures.InsertProject;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@Pname", Pname);
            Parameters.Add("@Pnumber", pnumber);
            Parameters.Add("@Plocation", Plocation);
            Parameters.Add("@Dnum", Dnum);
            return dbMan.ExecuteNonQuery(StoredProcedureName, Parameters);
        }

        public DataTable SelectDepNum()
        {
            string StoredProcedureName = StoredProcedures.SelectDepartmentNum;
            return dbMan.ExecuteReader(StoredProcedureName, null);

        }
        public DataTable SelectDepLoc()
        {
            String StoredProcedureName = StoredProcedures.SelectDepartmentLocation;
            return dbMan.ExecuteReader(StoredProcedureName, null);

        }

        public DataTable SelectProject(string location)
        {
            String StoredProcedureName = StoredProcedures.RetrieveProject;
            Dictionary<string, object> Parameters = new Dictionary<string, object>();
            Parameters.Add("@location", location);
            return dbMan.ExecuteReader(StoredProcedureName, Parameters);
        }
    }
}
        */