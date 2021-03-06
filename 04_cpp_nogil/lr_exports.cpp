#include <pybind11/pybind11.h>
#include <pybind11/stl.h>

#include <lr.hpp>

namespace lr = logisticregression;
namespace py = pybind11;

PYBIND11_MODULE(lrcpp, m) {
    py::class_<lr::LogisticRegression>(m, "LogisticRegression")
        .def(py::init<unsigned int>(),
            py::arg("num_threads") = 1)
        .def("compute_coefficients",
             &lr::LogisticRegression::compute_coefficients,
             py::call_guard<py::gil_scoped_release>());
}
