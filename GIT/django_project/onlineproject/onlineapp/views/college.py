from django.views import View
from django.shortcuts import render,get_object_or_404
from onlineapp.models import Colleges,Student,Marks
from django.views.generic import ListView,DetailView,CreateView
from onlineapp.forms.colleges_forms import *
from onlineapp.forms.student_form import *
from onlineapp.forms.marks_form import *
from django.urls import *



class CollegeView(View):
    def get(self,request,*args,**kwargs):
        colleges = Colleges.objects.values('Name', 'Acronym')
        #colleges = Colleges.objects.all()
        #import ipdb
        #ipdb.set_trace()
        pass

        return render(
            request,

            template_name='college.html',
            context = {
                'colleges': colleges,
            }
        )

class CollegeListView(ListView):
    model=Colleges
    context_object_name='colleges'
    def get_context_data(self,*,object_list=None,**kwargs):
        c= super(CollegeListView,self).get_context_data(**kwargs)
        return c


class CollegeDetailView(DetailView):
    model=Colleges
    context_object_name = 'colleges'
    template_name = 'college.html'

    def get_object(self,queryset=None):
        return get_object_or_404(Colleges,**self.kwargs)

    def get_context_data(self, **kwargs):
        context=super(CollegeDetailView,self).get_context_data(**kwargs)

        college=context.get('colleges')

        students = list(college.student_set.values('Name','Email_id','marks__Total').order_by("-marks__Total"))



        context.update({
        'colleges':students,
        'user_permission':self.request.user.get_all_permissions
        })

        return context

class CreateCollegeView(CreateView):
    model = Colleges
    form_class = AddCollege
    template_name = 'college_form.html'
    success_url = reverse_lazy('onlineapp:colleges_html')




class CreateStudentView(CreateView):
    model = Student
    form_class = StudentForm
    template_name = 'student_form.html'


    def get_context_data(self, **kwargs):
        context = super(CreateStudentView, self).get_context_data(**kwargs)
        test_form = MockTestForm()
        context.update({
            'student_form': context.get('form'),
            'test_form': test_form,
        })
        return context

    def post(self, request, *args, **kwargs):
        college = get_object_or_404(Colleges, pk=kwargs.get('college_id'))
        student_form = StudentForm(request.POST)
        test_form = MockTestForm(request.POST)

        if student_form.is_valid():
            student = student_form.save(commit=False)
            student.Colleges = college
            student.save()

            if test_form.is_valid():
                score = test_form.save(commit=False)
                score.Total = sum(test_form.cleaned_data.values())
                score.student = student
                score.save()